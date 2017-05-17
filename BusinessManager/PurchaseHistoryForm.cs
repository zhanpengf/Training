using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Data.SqlClient;
using System.Collections;

namespace BusinessManager
{
	// public enum InvFormType { sell, location };
	public partial class PurchaseHistoryForm : Form
	{
		public static MainForm mainForm;
		// a pointer to the sell history form
		public SellHistoryForm sellHistoryForm;
		public SqlDataAdapter sqlAdapterInv;
		public SqlDataAdapter sqlAdapterSell;
		public SqlDataAdapter sqlAdapterPurchase;
		public DataTable purchaseHistoryTable;
		public DataTable inventoryTable;
		public DataTable sellHistoryTable;
		public SqlCommandBuilder cmdBuilder;
		public float exRate;
		AddNewSellForm addNewSellForm;
		//public InvFormType formType;
		private bool formLoaded = false;
		public PurchaseHistoryForm()
		{
			InitializeComponent();
		}

		private void buttonSave_Click(object sender, EventArgs e)
		{
			try
			{
				sqlAdapterPurchase.Update(purchaseHistoryTable);
				//sqlAdapterSell.Update(inventoryTable);
				// reload the form
				radioButtonLocation_CheckedChanged(new object(), new EventArgs());
			}
			catch
			{
			}
		}

		public void Form1_Load(object sender, EventArgs e)
		{
			formLoaded = false;
			checkBoxSelectAll.Checked = false;
			radioButtonLocation_CheckedChanged(new object(), new EventArgs());
			dataGridView1.Columns["ColumnSellCount"].HeaderText = "Sell Count";
			dataGridView1.Columns["ColumnNewLocation"].Visible = false;
			buttonSell.Enabled = false;
			buttonUpdateLocation.Enabled = true;
			Text = "Purchase History";
			dataGridView1.Columns["Return Date"].Visible = false;
			dataGridView1.Columns["Product Name"].Width = 300;
			dataGridView1.Columns["ColumnSellCount"].Width = 60;
			dataGridView1.Columns["Quantity"].Width = 60;
			dataGridView1.Columns["Product ID"].Width = 60;
			dataGridView1.Columns["Purchasing Price"].Width = 65;
			dataGridView1.Columns["Current Location"].Width = 60;
			dataGridView1.Columns["Purchasing Date"].Width = 75;
			dataGridView1.Columns["Expiration Date"].Width = 75;
			// update datagridviewSum
			if (dataGridView1.Columns.Count != dataGridViewSum.Columns.Count)
			{
				for (int i = 0; i < dataGridView1.Columns.Count; i++)
				{
					dataGridViewSum.Columns.Add((DataGridViewColumn)dataGridView1.Columns[i].Clone());
				}
				updateSum();
			}
			reCalculateCellHighlight();
			formLoaded = true;
		}

		private void Form1_FormClosing(object sender, FormClosingEventArgs e)
		{
			// set focus to the save button to ensure the datagridview exit edit mode, to avoid
			// exception: System.InvalidOperationException: Operation is not valid because it 
			// results in a reentrant call to the SetCurrentCellAddressCore function.
			//
			buttonSave.Focus();
			this.Hide();
			e.Cancel = true; // this cancels the close event.
		}


		void dataGridView1_CurrentCellDirtyStateChanged(object sender, EventArgs e)
		{
			if (dataGridView1.IsCurrentCellDirty)
			{
				dataGridView1.CommitEdit(DataGridViewDataErrorContexts.Commit);
			}
		}

		public void dataGridView1_CellValueChanged(object sender,
			DataGridViewCellEventArgs e)
		{
			if (dataGridView1.Columns[e.ColumnIndex].Name == "ColumnNewLocation")
			{
				string newLocation = (string)dataGridView1.Rows[e.RowIndex].Cells[e.ColumnIndex].Value;

				foreach (DataGridViewRow row in dataGridView1.Rows)
				{
					if (row.Cells["ColumnCheck"].Value != null && (bool)row.Cells["ColumnCheck"].Value)
					{
						row.Cells["ColumnNewLocation"].Value = newLocation;

					}
				}
				dataGridView1.Invalidate();
			}
		}

		private void radioButtonLocation_CheckedChanged(object sender, EventArgs e)
		{
			string queryString = "";

			if (radioButtonAllLocation.Checked)
			{
				queryString = "SELECT * FROM PurchaseHistory";
			}
			else if (radioButtonInTransit.Checked)
			{
				queryString = "SELECT * FROM PurchaseHistory where [Current Location] = 'In Transit'";
			}
			else if (radioButtonTaiwan.Checked)
			{
				queryString = "SELECT * FROM PurchaseHistory where [Current Location] = 'Taiwan'";
			}
			else if (radioButtonTransitAndTaiwan.Checked)
			{
				queryString = "SELECT * FROM PurchaseHistory where [Current Location] = 'Taiwan' or [Current Location] = 'In Transit'";
			}
			else if (radioButtonShippingInUS.Checked)
			{
				queryString = "SELECT * FROM PurchaseHistory where [Current Location] = 'Shipping in US'";
			}
			else if (radioButtonUSA.Checked)
			{
				queryString = "SELECT * FROM PurchaseHistory where [Current Location] = 'USA'";
			}
			submitQuery(queryString);
		}

		private void submitQuery(string queryString)
		{
            MainForm.submitQuery(queryString, ref purchaseHistoryTable, sqlAdapterPurchase);
            formLoaded = false;
            MainForm.updateGridViewWithTable(ref dataGridView1, purchaseHistoryTable);
            formLoaded = true;
            updateSum();
		}

		private void updateSum()
		{
			try
			{
				// Update the sum
				if (dataGridViewSum.Rows.Count < 1)
				{
					dataGridViewSum.Rows.Add();
				}
				//dataGridViewSum.Rows.Clear();
				DataGridViewRow sumDR = dataGridViewSum.Rows[0];
				//dataGridViewSum.Rows.Add(sumDR);

				float sumQuantity = 0;
				float sumPurchasingPrice = 0;
				foreach (DataGridViewRow dr1 in dataGridView1.Rows)
				{
					sumPurchasingPrice += Convert.ToSingle(dr1.Cells["Quantity"].Value) * Convert.ToSingle(dr1.Cells["Purchasing Price"].Value);
					sumQuantity += Convert.ToSingle(dr1.Cells["Quantity"].Value);
				}
				sumDR.Cells["Purchasing Price"].Value = sumPurchasingPrice;
				sumDR.Cells["Quantity"].Value = sumQuantity;
			}
			catch
			{
			}
		}

		private void checkBoxSelectAll_CheckedChanged(object sender, EventArgs e)
		{
			if (checkBoxSelectAll.Checked)
			{
				for (int i = dataGridView1.Rows.Count - 2; i >= 0; i--)
				{
					DataGridViewRow row = dataGridView1.Rows[i];
					//if (row.Cells["ColumnCheck"].Value != null)
					{
						row.Cells["ColumnCheck"].Value = true;
						row.Cells["ColumnSellCount"].Value = row.Cells["Quantity"].Value;
					}
				}
			}
			else
			{
				for (int i = dataGridView1.Rows.Count - 2; i >= 0; i--)
				{
					DataGridViewRow row = dataGridView1.Rows[i];
					//if (row.Cells["ColumnCheck"].Value != null)
					{
						row.Cells["ColumnCheck"].Value = false;
						row.Cells["ColumnSellCount"].Value = "";
					}
				}

			}


		}

		private void dataGridView1_DataError(object sender, DataGridViewDataErrorEventArgs e)
		{

		}

		private void checkBoxHighlight_CheckedChanged(object sender, EventArgs e)
		{
			if (!checkBoxHighlight.Checked)
			{
				foreach (DataGridViewRow row in dataGridView1.Rows)
				{
					var cells = row.Cells;
					foreach (DataGridViewCell cell in cells)
					{
						cell.Style.BackColor = Color.White;
					}
				}
			}
			else
			{
				reCalculateCellHighlight();
			}
		}

		private void buttonApplySQL_Click(object sender, EventArgs e)
		{
			try
			{
				submitQuery(textBoxSQL.Text);
			}
			catch
			{
				MessageBox.Show("Invalid query.");
			}
		}


		private void buttonShowAll_Click(object sender, EventArgs e)
		{
			string queryString = "SELECT * FROM PurchaseHistory";
			submitQuery(queryString);
		}

		private void dataGridView1_RowsAdded(object sender, DataGridViewRowsAddedEventArgs e)
		{
			if (formLoaded)
			{
				reCalculateCellHighlight();
			}
		}

		private void dataGridView1_RowsRemoved(object sender, DataGridViewRowsRemovedEventArgs e)
		{
			if (formLoaded)
			{
				reCalculateCellHighlight();
			}
		}

		private void dataGridView1_Sorted(object sender, EventArgs e)
		{
			if (formLoaded)
			{
				reCalculateCellHighlight();
			}
		}

		private void reCalculateCellHighlight()
		{
			Color prevColor = Color.White;
			for (int rowIndex = 0; rowIndex < dataGridView1.Rows.Count; rowIndex++)
			{
				if (dataGridView1.Rows[rowIndex].Cells["Product Name"].Value != null)
				{
					string productName = dataGridView1.Rows[rowIndex].Cells["Product Name"].Value.ToString().ToLower();
					string[] splitted = productName.Split(new char[1] { ' ' });
					string[] splittedPrevRow = splitted;
					Color rowColor = prevColor;

					if (rowIndex > 0)
					{
						splittedPrevRow = dataGridView1.Rows[rowIndex - 1].Cells["Product Name"].Value.ToString().ToLower().Split(new char[1] { ' ' });
					}
					if (splittedPrevRow.Length > 1 && splitted.Length > 1 && splitted[0] == splittedPrevRow[0] && splitted[1] == splittedPrevRow[1])
					{
						rowColor = prevColor;
					}
					else
					{
						rowColor = prevColor == Color.White ? Color.LightGray : Color.White;
						prevColor = rowColor;
					}
					var cells = dataGridView1.Rows[rowIndex].Cells;
					foreach (DataGridViewCell cell in cells)
					{
						cell.Style.BackColor = rowColor;
					}
				}
			}
		}

		private void dataGridView1_ColumnWidthChanged(object sender, DataGridViewColumnEventArgs e)
		{
			if (dataGridViewSum != null && dataGridView1.Columns.Count == dataGridViewSum.Columns.Count)
			{
				dataGridViewSum.Columns[e.Column.Index].Width = e.Column.Width;
			}
		}

	}
}
