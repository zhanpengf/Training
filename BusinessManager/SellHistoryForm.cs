﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Data.SqlServerCe;

namespace BusinessManager
{
    /// <summary>
    /// Normal is for viewing and editing SellHistory
    /// ChooseExisting is specifically for adding new items to an existing sell history
    /// </summary>
    public enum SellHistFormType { Normal, ChooseExisting };
    
    public partial class SellHistoryForm : Form
    {
        public static MainForm mainForm; 
        public SqlCeDataAdapter sqlAdapter;
        public SqlCeConnection sqlConnection;
        public DataTable sellHistoryTable;
        public SqlCeCommandBuilder cmdBuilder;

        public DataTable purchaseHistoryTable;
        public SqlCeDataAdapter sqlAdapterPurchase;
        public float exRate;
        private bool duringInit;
        public SellHistFormType formType;
        public int ChosenID = 0; 
        const int _7_11_column_index = 3; 
        public SellHistoryForm()
        {
            InitializeComponent();
            duringInit = true;        
            this.dateTimePickerFrom.Value = new DateTime(DateTime.Now.Year, DateTime.Now.Month, 1);
            this.dateTimePickerTo.Value = new DateTime(DateTime.Now.Year, DateTime.Now.Month, 1, 23, 59, 59).AddMonths(1).AddDays(-1);
            duringInit = false; 
        }

        public void SellHistoryForm_Load(object sender, EventArgs e)
        {
            // reload form
            dateTimePicker_ValueChanged(new object(), new EventArgs());
            dataGridView1.Columns["Products"].Width = 300;
            dataGridView1.Columns["Selling Price"].Width = 60;
            dataGridView1.Columns["Cost"].Width = 60;
            dataGridView1.Columns["Cost_TWD"].Width = 65;
            dataGridView1.Columns["International Shipping"].Width = 70;
            dataGridView1.Columns["InterShipping_TWD"].Width = 65;
            dataGridView1.Columns["InterShipping_TWD"].HeaderText = "Inter Shipping TWD";  
            dataGridView1.Columns["Domestic Shipping"].Width = 65;
            dataGridView1.Columns["Customer Paid Shipping"].Width = 75;
            dataGridView1.Columns["Profit"].Width = 60;
            dataGridView1.Columns["Date"].Width = 75;
            dataGridView1.Columns["Quantity"].Width = 60;
            dataGridView1.Columns["Sell ID"].Width = 60;
            dataGridView1.Columns["Paid"].Width = 40;
            dataGridView1.Columns["Shipped"].Width = 50;
            dataGridView1.Columns["7-11"].Width = 50;
            dataGridView1.Columns["7-11"].HeaderText = "7-11 Ruten"; 

            if (formType == SellHistFormType.Normal)
            {
                buttonSave.Text = "Save"; 
            }
            else if (formType == SellHistFormType.ChooseExisting)
            {
                buttonSave.Text = "Choose";
                ChosenID = -1; 
            }

            // update datagridviewSum
            if (dataGridView1.Columns.Count != dataGridViewSum.Columns.Count)
            {
                for (int i = 0; i < dataGridView1.Columns.Count; i++)
                {
                    // special treatment to column _7_11_column_index, where the sum is a number, while the original column is a checkbox
                    if (i == _7_11_column_index)
                    {
                        dataGridViewSum.Columns.Add("7-11", "");
                        dataGridViewSum.Columns[i].Width = dataGridView1.Columns[i].Width; 
                        //dataGridViewSum.Columns.Add(
                        dataGridViewSum.Rows[0].Cells[i].Value = "";
                    }
                    else
                    {
                        dataGridViewSum.Columns.Add((DataGridViewColumn)dataGridView1.Columns[i].Clone());
                    }
                }
                updateSum();
            }
            
        }

        private void dataGridView1_CellValueChanged(object sender, DataGridViewCellEventArgs e)
        {
            if (e.RowIndex >= 0)
            {
                DataGridViewRow dr = dataGridView1.Rows[e.RowIndex];
                if (e.ColumnIndex == _7_11_column_index)
                {
                    if (dataGridViewSum.Rows.Count < 1)
                    {
                        dataGridViewSum.Rows.Add();
                    }
                    //dataGridViewSum.Rows.Clear();
                    DataGridViewRow sumDR = dataGridViewSum.Rows[0];
                    int sum7_11 = 0;
                    foreach (DataGridViewRow dr1 in dataGridView1.Rows)
                    {
                        if (dr1.Cells != null && dr1.Cells["7-11"].Value != null 
                            && !DBNull.Value.Equals(dr1.Cells["7-11"].Value) 
                            && ((bool)dr1.Cells["7-11"].Value))
                        {
                            sum7_11++;
                        }
                        //sum7_11++; 
                        //try
                        //{
                        //    sum7_11 += Convert.ToInt16(dr1.Cells["7-11"].Value);
                        //}
                        //catch
                        //{
                        //}
                    }
                    sumDR.Cells["7-11"].Value = sum7_11 * 60;
                }
                else
                {
                    try
                    {
                        this.dataGridView1.CellValueChanged -= new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView1_CellValueChanged);
                        //if this is a new row, initialize the datarow first
                        // this logic seems weird, commented out 04/08/2015
                        //if ((DBNull.Value.Equals(dr.Cells["Cost_TWD"].Value))
                        //    || (DBNull.Value.Equals(dr.Cells["Cost"].Value)))
                        //{
                        //    object temp = dr.Cells[e.ColumnIndex].Value;
                        //    //dr.Cells["Sell ID"].Value = ""; 
                        //    dr.Cells["Products"].Value = "";
                        //    dr.Cells["Selling Price"].Value = 0;
                        //    dr.Cells["Quantity"].Value = 0;
                        //    dr.Cells["Notes"].Value = "";
                        //    dr.Cells["Date"].Value = DateTime.Now;
                        //    dr.Cells["International Shipping"].Value = 0;
                        //    dr.Cells["Cost"].Value = 0;
                        //    dr.Cells["Profit"].Value = 0;
                        //    dr.Cells["Domestic Shipping"].Value = 0;
                        //    dr.Cells["Customer Paid Shipping"].Value = 0;
                        //    dr.Cells[e.ColumnIndex].Value = temp;
                        //}
                        if (DBNull.Value.Equals(dr.Cells[e.ColumnIndex].Value))
                        {
                            dr.Cells[e.ColumnIndex].Value = 0;
                        }

                        dr.Cells["InterShipping_TWD"].Value = Convert.ToSingle(dr.Cells["International Shipping"].Value) * exRate;
                        dr.Cells["Cost_TWD"].Value = Convert.ToSingle(dr.Cells["Cost"].Value) * exRate;

                        dr.Cells["Profit"].Value = Convert.ToSingle(dr.Cells["Selling Price"].Value) - Convert.ToSingle(dr.Cells["Cost_TWD"].Value)
                            - Convert.ToSingle(dr.Cells["InterShipping_TWD"].Value) -
                            Convert.ToSingle(dr.Cells["Domestic Shipping"].Value) +
                            Convert.ToSingle(dr.Cells["Customer Paid Shipping"].Value);

                        this.dataGridView1.CellValueChanged += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView1_CellValueChanged);
                        updateSum();
                    }
                    catch
                    {
                        this.dataGridView1.CellValueChanged += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView1_CellValueChanged);
                    }
                }
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
                float sumProfit = 0;
                float sumCost = 0;
                float sumCost_TWD = 0;
                float sumInterShipping = 0;
                float sumInterShippingTWD = 0;
                float sumSellingPrice = 0;
                float sumDomShipping = 0;
                float sumCustPaidShipping = 0;
                float sumQuantity = 0;
                int sum7_11 = 0; 
                foreach (DataGridViewRow dr1 in dataGridView1.Rows)
                {
                    sumProfit += Convert.ToSingle(dr1.Cells["Profit"].Value);
                    sumSellingPrice += Convert.ToSingle(dr1.Cells["Selling Price"].Value);
                    sumCost += Convert.ToSingle(dr1.Cells["Cost"].Value);
                    sumCost_TWD += Convert.ToSingle(dr1.Cells["Cost_TWD"].Value);
                    sumCustPaidShipping += Convert.ToSingle(dr1.Cells["Customer Paid Shipping"].Value);
                    sumDomShipping += Convert.ToSingle(dr1.Cells["Domestic Shipping"].Value);
                    sumInterShipping += Convert.ToSingle(dr1.Cells["International Shipping"].Value);
                    sumInterShippingTWD += Convert.ToSingle(dr1.Cells["InterShipping_TWD"].Value);
                    sumQuantity += Convert.ToSingle(dr1.Cells["Quantity"].Value);
                    if (dr1.Cells != null && dr1.Cells["7-11"].Value != null
                            && !DBNull.Value.Equals(dr1.Cells["7-11"].Value)
                            && ((bool)dr1.Cells["7-11"].Value))
                    {
                        sum7_11++;
                    }
                }
                sumDR.Cells["Products"].Value = "Sum";
                sumDR.Cells["Profit"].Value = sumProfit;
                sumDR.Cells["Selling Price"].Value = sumSellingPrice;
                sumDR.Cells["Cost"].Value = sumCost;
                sumDR.Cells["Cost_TWD"].Value = sumCost_TWD;
                sumDR.Cells["Customer Paid Shipping"].Value = sumCustPaidShipping;
                sumDR.Cells["Domestic Shipping"].Value = sumDomShipping;
                sumDR.Cells["International Shipping"].Value = sumInterShipping;
                sumDR.Cells["InterShipping_TWD"].Value = sumInterShippingTWD;
                sumDR.Cells["Quantity"].Value = sumQuantity;
                sumDR.Cells["7-11"].Value = sum7_11 * 60; 
            }
            catch
            {
            }
        }

        private void buttonSave_Click(object sender, EventArgs e)
        {
            try
            {
                if (formType == SellHistFormType.Normal)
                {
                    int seletedRowIndex = dataGridView1.FirstDisplayedScrollingRowIndex;//dataGridView1.SelectedRows[0].Index;
                    sqlAdapter.Update(sellHistoryTable);
                    // reload the form
                    dateTimePicker_ValueChanged(new object(), new EventArgs());
                    dataGridView1.FirstDisplayedScrollingRowIndex = seletedRowIndex;
                }
                else if (formType == SellHistFormType.ChooseExisting)
                {
                    try
                    {
                        ChosenID = Convert.ToInt32(dataGridView1.SelectedRows[0].Cells["Sell ID"].Value);
                    }
                    catch
                    {
                        ChosenID = -1; 
                    }
                    Close();
                }
            }
            catch
            {
                ChosenID = -1;
            }

        }

        private void dateTimePicker_ValueChanged(object sender, EventArgs e)
        {
            if (!duringInit)
            {
                //try
                {                    
                    string queryString = "";

                    DateTime dtFrom = dateTimePickerFrom.Value;
                    DateTime dtTo = dateTimePickerTo.Value;
                    queryString = "SELECT * FROM SellHistory where Date>=@dtFrom and Date<=@dtTo";


                    SqlCeCommand cmd = new SqlCeCommand(queryString, sqlAdapter.SelectCommand.Connection);
                    cmd.Parameters.AddWithValue("dtFrom", dtFrom);
                    cmd.Parameters.AddWithValue("dtTo", dtTo);
                    SqlCeDataReader reader = cmd.ExecuteReader();
                    sellHistoryTable.Clear();
                    sellHistoryTable.Load(reader);
                    dataGridView1.DataSource = sellHistoryTable;
                                        
                    float profit = 0;
                    foreach (DataGridViewRow dgRow in dataGridView1.Rows)
                    {
                        float temp = 0;
                        try
                        {
                            temp = Convert.ToSingle(dgRow.Cells["Profit"].Value);
                        }
                        catch
                        {
                            temp = 0;
                        }
                        profit += temp;
                    }
                    labelProfit.Text = profit.ToString("#.##");
                    labelItemsSold.Text = (dataGridView1.Rows.Count - 1).ToString();
                    updateSum();
                }
                //catch
                {
                    
                }
            }
        }

        private void buttonUpdateSum_Click(object sender, EventArgs e)
        {
            updateSum();
        }

        private void SellHistoryForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            // set focus to the save button to ensure the datagridview exit edit mode, to avoid
            // exception: System.InvalidOperationException: Operation is not valid because it 
            // results in a reentrant call to the SetCurrentCellAddressCore function.
            //
            buttonSave.Focus();
            this.Hide();
            e.Cancel = true; // this cancels the close event.
        }

        private void buttonAddShipping_Click(object sender, EventArgs e)
        {
            this.dataGridView1.CellValueChanged -= new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView1_CellValueChanged);

            // Add to purchase history table
            DataRow dr2 = purchaseHistoryTable.NewRow();
            {
                dr2["Product Name"] = "Shipping " + comboBoxShippingType.Text;
                dr2["Purchasing Price"] = numericCost.Value;
                dr2["Quantity"] = 1;
                dr2["Purchasing Date"] = DateTime.Now;
                dr2["Current Location"] = "Taiwan"; 
            }
            purchaseHistoryTable.Rows.Add(dr2);
            sqlAdapterPurchase.Update(purchaseHistoryTable);
           

            DataRow dr = sellHistoryTable.NewRow();
            {
                dr["Products"] = "Shipping " + comboBoxShippingType.Text;
                dr["Selling Price"] = 0;
                dr["Quantity"] = 0;
                dr["Notes"] = "";
                dr["Date"] = DateTime.Now;
                dr["International Shipping"] = numericCost.Value;
                dr["Cost"] = 0;
                dr["Profit"] = 0;
                dr["Domestic Shipping"] = 0;
                dr["Customer Paid Shipping"] = 0;
            }

            dr["InterShipping_TWD"] = Convert.ToSingle(dr["International Shipping"]) * exRate;
            dr["Cost_TWD"] = Convert.ToSingle(dr["Cost"]) * exRate;

            dr["Profit"] = Convert.ToSingle(dr["Selling Price"]) - Convert.ToSingle(dr["Cost_TWD"])
                - Convert.ToSingle(dr["InterShipping_TWD"]) -
                Convert.ToSingle(dr["Domestic Shipping"]) +
                Convert.ToSingle(dr["Customer Paid Shipping"]);
            sellHistoryTable.Columns["Sell ID"].AllowDBNull = true;
            sellHistoryTable.Rows.Add(dr);
            //            table.AcceptChanges();
            //            Application.DoEvents();
            this.dataGridView1.CellValueChanged += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView1_CellValueChanged);

            updateSum();
            dataGridView1.FirstDisplayedScrollingRowIndex = dataGridView1.Rows.Count - 1;
        }

        private void buttonRefresh_Click(object sender, EventArgs e)
        {
            dataGridView1.Refresh();
            dataGridView1.Visible = true;
            dataGridViewSum.Visible = true;           
        }

        private void buttonAddNewToInv_Click(object sender, EventArgs e)
        {
            mainForm.buttonAddNewToInv.PerformClick();
        }

        private void buttonUpdateLocation_Click(object sender, EventArgs e)
        {
            mainForm.buttonUpdateLocation.PerformClick();
        }

        private void buttonSell_Click(object sender, EventArgs e)
        {
            mainForm.buttonSell.PerformClick();
        }

        private void buttonChart_Click(object sender, EventArgs e)
        {
            // this work for date
            //string getDate = 
            //"CONVERT(DATETIME,CAST(DATEPART(month, [Date]) AS NVARCHAR(50)) + '-' + " +
            //    "CAST(DATEPART(day, [Date]) AS NVARCHAR(50)) + '-' +" +
            //    "CAST(DATEPART(year, [Date]) AS NVARCHAR(50)), 121)";

            string getDate = "CAST(DATEPART(year, [Date]) AS NVARCHAR(50)) + '-' + " +
                "CAST(DATEPART(month, [Date]) AS NVARCHAR(50))";

            string queryString = "SELECT sum([Profit]) as [Profit], sum([Selling Price]) as [Revenue], " +
            getDate + " as Quantity, min(Date) as Month from SellHistory " +
            "group by " + getDate;

            // sql CE doesn't support year() and month() function
            //string queryString = "select year(Date) as y, month(Date) as m, sum(Profit) as p " +
            //"from SellHistory group by year(Date), month(Date)";

            DataTable tempTable = new DataTable(); 
            SqlCeCommand cmd = new SqlCeCommand(queryString, sqlAdapter.SelectCommand.Connection);
            SqlCeDataReader reader = cmd.ExecuteReader();
            tempTable.Clear();
            tempTable.Load(reader);

            tempTable.DefaultView.Sort = "[Month] ASC";
            tempTable = tempTable.DefaultView.ToTable(); 

            ChartingForm chartingForm = new ChartingForm();
            string[] yNames = new string[2];
            yNames[0] = "Profit";
            yNames[1] = "Revenue"; 
            chartingForm.updateChart(tempTable, "Month", yNames);
            chartingForm.ShowDialog();
        }

        private void dataGridView1_CurrentCellDirtyStateChanged(object sender, EventArgs e)
        {
            if (dataGridView1.IsCurrentCellDirty)
            {
                dataGridView1.CommitEdit(DataGridViewDataErrorContexts.Commit);
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
