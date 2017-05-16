using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Data.SqlServerCe;
using System.Collections; 

namespace BusinessManager
{
    public enum InvFormType { sell, location };
    public partial class InventoryListForm : Form
    {
        public static MainForm mainForm; 
        // a pointer to the sell history form
        public SellHistoryForm sellHistoryForm;
        public SqlCeDataAdapter sqlAdapterInv;
        public SqlCeDataAdapter sqlAdapterSell;
        public DataTable inventoryTable;
        public DataTable sellHistoryTable;
        public SqlCeCommandBuilder cmdBuilder;
        public float exRate;
        AddNewSellForm addNewSellForm;
        public InvFormType formType;
        private bool formLoaded = false;
        public InventoryListForm()
        {
            InitializeComponent();
        }

        private void buttonSave_Click(object sender, EventArgs e)
        {
            try
            {
                sqlAdapterInv.Update(inventoryTable);
                // reload the form
                radioButtonLocation_CheckedChanged(new object(), new EventArgs());
            }
            catch
            {
            }
        }

        public void Form1_Load(object sender, EventArgs e)
        {
            //dataGridView1.DataSource = inventoryTable;
            //inventoryTable.Clear();
            //sqlAdapterInv.Fill(inventoryTable);
            formLoaded = false; 
            checkBoxSelectAll.Checked = false;
            radioButtonLocation_CheckedChanged(new object(),new EventArgs()); 

            if (formType == InvFormType.location)
            {
                dataGridView1.Columns["ColumnSellCount"].HeaderText = "Move Count";
                dataGridView1.Columns["ColumnNewLocation"].Visible = true;
                buttonNext.Visible = false;
                buttonUpdate.Visible = true;
                buttonSell.Enabled = true;
                buttonUpdateLocation.Enabled = false; 
                Text = "Update Location";
            }
            else if (formType == InvFormType.sell)
            {
                dataGridView1.Columns["ColumnSellCount"].HeaderText = "Sell Count";
                dataGridView1.Columns["ColumnNewLocation"].Visible = false;
                buttonNext.Visible = true;
                buttonUpdate.Visible = false;
                buttonSell.Enabled = false;
                buttonUpdateLocation.Enabled = true; 
                Text = "Sell";
                //dataGridView1.Visible = true; 
            }
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

        private void buttonNext_Click(object sender, EventArgs e)
        {
            
            if (addNewSellForm == null)
            {
                addNewSellForm = new AddNewSellForm();
            }
            addNewSellForm.sellHistoryForm = sellHistoryForm; 
            addNewSellForm.exRate = exRate;
            string products = "";
            int totalQuantity = 0;
            int quantity = 0;
            float purchasingPrice = 0;
            float cost = 0;
            foreach (DataGridViewRow row in dataGridView1.Rows)
            {
                if (row.Cells["ColumnCheck"].Value != null && (bool)row.Cells["ColumnCheck"].Value)
                {
                    // item is checked
                    try
                    {
                        quantity = Convert.ToInt32(row.Cells["ColumnSellCount"].Value);
                    }
                    catch
                    {
                        quantity = 0;
                    }

                    try
                    {
                        purchasingPrice = Convert.ToSingle(row.Cells["Purchasing Price"].Value);
                    }
                    catch
                    {
                        purchasingPrice = 0;
                    }

                    products += ("<" + row.Cells["Product Name"].Value.ToString() +
                        " " + quantity.ToString() + " * $" + purchasingPrice.ToString() + "> ");
                    totalQuantity += quantity;
                    cost += purchasingPrice * quantity;
                }
            }
            addNewSellForm.products = products;
            addNewSellForm.quantity = totalQuantity;
            addNewSellForm.cost = cost;
            if (quantity == 0)
            {
                MessageBox.Show("Quantity has to be larger than 0.");
                return;
            }
            if (DialogResult.OK == addNewSellForm.ShowDialog())
            {
                DataRow dr;

                if (!addNewSellForm.addToExist)
                {
                    dr = sellHistoryTable.NewRow();
                    dr["Products"] = addNewSellForm.products;
                    dr["Date"] = addNewSellForm.sellingDate;
                    dr["Quantity"] = addNewSellForm.quantity;
                    dr["International Shipping"] = addNewSellForm.internationalShipping;
                    dr["InterShipping_TWD"] = addNewSellForm.internationalShipping * exRate;
                    dr["Domestic Shipping"] = addNewSellForm.domesticShipping;
                    dr["Customer Paid Shipping"] = addNewSellForm.customerPaidShipping;
                    dr["Profit"] = addNewSellForm.profit;
                    dr["Notes"] = addNewSellForm.notes;
                    dr["Selling Price"] = addNewSellForm.sellingPrice;
                    dr["Cost"] = addNewSellForm.cost;
                    dr["Cost_TWD"] = addNewSellForm.cost * exRate;
                }
                else
                {
                    DataColumn[] keys = new DataColumn[1];
                    keys[0] = sellHistoryTable.Columns["Sell ID"];
                    sellHistoryTable.PrimaryKey = keys;
                    dr = sellHistoryTable.Rows.Find(addNewSellForm.chosenID);
                    // if PrimaryKey not set to null, "Column "Sell ID" is contrained to be unique" exception will be thrown when trying to add rows to sellHistoryTable
                    sellHistoryTable.PrimaryKey = null;
                    // Calling "sellHistoryTable.PrimaryKey = keys;" above sets AllowDBNull to false. Reset it to true here. 
                    sellHistoryTable.Columns["Sell ID"].AllowDBNull = true;

                    dr["Products"] += addNewSellForm.products;
                    dr["Date"] = addNewSellForm.sellingDate;
                    dr["Quantity"] = Convert.ToInt32(dr["Quantity"]) + addNewSellForm.quantity;
                    dr["International Shipping"] = Convert.ToSingle(dr["International Shipping"]) + addNewSellForm.internationalShipping;
                    dr["InterShipping_TWD"] = Convert.ToSingle(dr["InterShipping_TWD"]) + addNewSellForm.internationalShipping * exRate;
                    dr["Domestic Shipping"] = Convert.ToSingle(dr["Domestic Shipping"]) + addNewSellForm.domesticShipping;
                    dr["Customer Paid Shipping"] = Convert.ToSingle(dr["Customer Paid Shipping"]) + addNewSellForm.customerPaidShipping;
                    dr["Profit"] = Convert.ToSingle(dr["Profit"]) + addNewSellForm.profit;
                    dr["Notes"] += addNewSellForm.notes;
                    dr["Selling Price"] = Convert.ToSingle(dr["Selling Price"]) + addNewSellForm.sellingPrice;
                    dr["Cost"] = Convert.ToSingle(dr["Cost"]) + addNewSellForm.cost;
                    dr["Cost_TWD"] = Convert.ToSingle(dr["Cost_TWD"]) + addNewSellForm.cost * exRate;
                }


                // update inventory
                //foreach (DataGridViewRow row in dataGridView1.Rows)
                bool hasError = false;
                for (int i = dataGridView1.Rows.Count - 1; i >= 0; i--)
                {
                    DataGridViewRow row = dataGridView1.Rows[i];
                    if (row.Cells["ColumnCheck"].Value != null && (bool)row.Cells["ColumnCheck"].Value)
                    {
                        // item is checked
                        int inventoryCount = 0;
                        int productID = (int)row.Cells["Product ID"].Value;
                        try
                        {
                            inventoryCount = Convert.ToInt32(row.Cells["Quantity"].Value);
                        }
                        catch
                        {
                            inventoryCount = 0;
                        }
                        try
                        {
                            quantity = Convert.ToInt32(row.Cells["ColumnSellCount"].Value);
                        }
                        catch
                        {
                            quantity = 0;
                        }
                        int remainCount = inventoryCount - quantity;
                        row.Cells["Quantity"].Value = remainCount;

                        row.Cells["ColumnCheck"].Value = false;
                        row.Cells["ColumnSellCount"].Value = "";

                        if (remainCount < 0)
                        {
                            MessageBox.Show("Remaining quantity < 0! Product ID: " + row.Cells["Product ID"].Value.ToString(), "Error", MessageBoxButtons.OK,
                                MessageBoxIcon.Error);
                            hasError = true;
                            break;
                        }
                        else if (remainCount == 0)
                        {
                            dataGridView1.Rows.Remove(row);
                        }
                        else
                        {

                        }
                        //SqlCeCommand cmd = new SqlCeCommand("Update Inventory set Quantity = @quantity where [Product ID] = @productID", sqlAdapterInv.SelectCommand.Connection);
                        //cmd.Parameters.AddWithValue("quantity", row.Cells["Quantity"].Value);
                        //cmd.Parameters.AddWithValue("productID", productID);
                        //int affectedRows = cmd.ExecuteNonQuery();
                        //inventoryTable.GetChanges();
                    }
                }
                if (!hasError)
                {
                    if (!addNewSellForm.addToExist)
                    {
                        sellHistoryTable.Columns["Sell ID"].AllowDBNull = true;
                        sellHistoryTable.Rows.Add(dr);
                    }
                    sqlAdapterSell.Update(sellHistoryTable);
                    sqlAdapterInv.Update(inventoryTable);
                }
                // reload the form
                radioButtonLocation_CheckedChanged(new object(), new EventArgs());
            }
        }

        private void buttonUpdateLocation_Click(object sender, EventArgs e)
        {
            //foreach (DataGridViewRow row in dataGridView1.Rows)
            for (int i = dataGridView1.Rows.Count - 1; i >= 0; i--)
            {
                DataGridViewRow row = dataGridView1.Rows[i];
                int quantity = 0;
                if (row.Cells["ColumnCheck"].Value != null && (bool)row.Cells["ColumnCheck"].Value)
                {
                    // item is checked

                    int inventoryCount = 0;
                    int productID = (int)row.Cells["Product ID"].Value;
                    try
                    {
                        inventoryCount = Convert.ToInt32(row.Cells["Quantity"].Value);
                    }
                    catch
                    {
                        inventoryCount = 0;
                    }
                    try
                    {
                        quantity = Convert.ToInt32(row.Cells["ColumnSellCount"].Value);
                    }
                    catch
                    {
                        quantity = 0;
                    }
                    int remainCount = inventoryCount - quantity;
                    if (remainCount >= 0)
                    {
                        DataRow dr = inventoryTable.NewRow();
                        foreach (DataGridViewColumn col in dataGridView1.Columns)
                        {
                            if (col.Name != "Product ID")
                            {
                                try
                                {
                                    dr[col.Name] = row.Cells[col.Name].Value;
                                }
                                catch
                                {
                                }
                            }
                        }

                        dr["Quantity"] = quantity;
                        dr["Current Location"] = (String)row.Cells["ColumnNewLocation"].Value;
                        inventoryTable.Rows.Add(dr);
                        row.Cells["Quantity"].Value = remainCount;
                        //SqlCeCommand cmd = new SqlCeCommand("Update Inventory set Quantity = @quantity where [Product ID] = @productID", sqlAdapterInv.SelectCommand.Connection);
                        //cmd.Parameters.AddWithValue("quantity", row.Cells["Quantity"].Value);
                        //cmd.Parameters.AddWithValue("productID", productID);
                        //int affectedRows = cmd.ExecuteNonQuery();
                        //inventoryTable.GetChanges();
                        if (remainCount == 0)
                        {
                            dataGridView1.Rows.Remove(row);
                        }
                        else
                        {
                            row.Cells["ColumnCheck"].Value = false;
                            row.Cells["ColumnSellCount"].Value = "";
                        }
                    }
                    else
                    {
                        MessageBox.Show("Remaining quantity < 0!", "Error", MessageBoxButtons.OK,
                            MessageBoxIcon.Error);
                    }
                }
            }
            sqlAdapterInv.Update(inventoryTable);
            // In order to update the product ID. There should be a better way to do this. 
            // reload the form
            radioButtonLocation_CheckedChanged(new object(), new EventArgs());
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
                queryString = "SELECT * FROM Inventory";
            }
            else if (radioButtonInTransit.Checked)
            {
                queryString = "SELECT * FROM Inventory where [Current Location] = 'In Transit'";                
            }
            else if (radioButtonTaiwan.Checked)
            {
                queryString = "SELECT * FROM Inventory where [Current Location] = 'Taiwan'";
            }
            else if (radioButtonTransitAndTaiwan.Checked)
            {
                queryString = "SELECT * FROM Inventory where [Current Location] = 'Taiwan' or [Current Location] = 'In Transit'";
            }
            else if (radioButtonShippingInUS.Checked)
            {
                queryString = "SELECT * FROM Inventory where [Current Location] = 'Shipping in US'";
            }
            else if (radioButtonUSA.Checked)
            {
                queryString = "SELECT * FROM Inventory where [Current Location] = 'USA'";
            }
            submitQuery(queryString);             
        }

        private void submitQuery(string queryString)
        {
            SqlCeCommand cmd = new SqlCeCommand(queryString, sqlAdapterInv.SelectCommand.Connection);
            SqlCeDataReader reader = cmd.ExecuteReader();
            inventoryTable.Clear();
            inventoryTable.Load(reader);
            dataGridView1.DataSource = inventoryTable;
            updateSum(); 
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

        private void buttonAddNewToInv_Click(object sender, EventArgs e)
        {
            mainForm.buttonAddNewToInv.PerformClick();
            Form1_Load(new object(), new EventArgs()); 
        }

        private void buttonSell_Click(object sender, EventArgs e)
        {
            if (formType != InvFormType.sell)
            {
                formType = InvFormType.sell;
                Form1_Load(new object(), new EventArgs()); 
            }
        }

        private void buttonUpdateLocation_Click_1(object sender, EventArgs e)
        {
            if (formType != InvFormType.location)
            {
                formType = InvFormType.location;
                Form1_Load(new object(), new EventArgs()); 
            }
        }

        private void buttonShowSellHistory_Click(object sender, EventArgs e)
        {
            mainForm.buttonShowSellHistory.PerformClick();            
        }

        //private void paintHighLight()
        //{
        //    if (checkBoxHighlight.Checked)
        //    {
        //        isPaintingHighLight = true; 
        //        //MessageBox.Show("cell painting"); 
        //        var visibleRowsCount = dataGridView1.DisplayedRowCount(true);
        //        var firstDisplayedRowIndex = dataGridView1.FirstDisplayedCell.RowIndex;
        //        var lastvisibleRowIndex = (firstDisplayedRowIndex + visibleRowsCount) - 1;
        //        Color prevColor = Color.White;
        //        for (int rowIndex = firstDisplayedRowIndex; rowIndex <= lastvisibleRowIndex; rowIndex++)
        //        {
        //            // This cell is visible...
        //            if (dataGridView1.Rows[rowIndex].Cells["Product Name"].Value != null)
        //            {
        //                string productName = dataGridView1.Rows[rowIndex].Cells["Product Name"].Value.ToString().ToLower();
        //                string[] splitted = productName.Split(new char[1] { ' ' });
        //                string[] splittedPrevRow = splitted;
        //                Color rowColor = prevColor;

        //                // old way
        //                //if (rowIndex > 0)
        //                //{
        //                //    splittedPrevRow = dataGridView1.Rows[rowIndex - 1].Cells["Product Name"].Value.ToString().ToLower().Split(new char[1] { ' ' });
        //                //}
        //                //if (splittedPrevRow.Length > 1 && splitted.Length > 1 && splitted[0] == splittedPrevRow[0] && splitted[1] == splittedPrevRow[1])
        //                //{
        //                //    rowColor = prevColor;
        //                //}
        //                //else
        //                //{
        //                //    rowColor = prevColor == Color.White ? Color.LightGray : Color.White;
        //                //    prevColor = rowColor;
        //                //}

        //                // new way
        //                rowColor = (Color)rowColors[rowIndex]; 

        //                var cells = dataGridView1.Rows[rowIndex].Cells;
        //                foreach (DataGridViewCell cell in cells)
        //                {
        //                    if (cell.Displayed)
        //                    {
        //                        cell.Style.BackColor = rowColor;
        //                    }
        //                }
        //            }
        //        }
        //    }
        //    isPaintingHighLight = false; 
        //}

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

        private void buttonShowAll_Click(object sender, EventArgs e)
        {
            string queryString = "SELECT * FROM Inventory";
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
