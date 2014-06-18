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
    public partial class MainForm : Form
    {
        SqlCeConnection sqlConnectionInv;
        SqlCeDataAdapter sqlAdapterInv;
        DataTable inventoryTable =new DataTable();        
        SqlCeCommandBuilder cmdBuilderInv;
        AddNewInventoryForm addNewInvForm;
        InventoryListForm inventoryListForm;

        SqlCeConnection sqlConnectionSell;
        SqlCeDataAdapter sqlAdapterSell;
        DataTable sellHistoryTable = new DataTable(); 
        SqlCeCommandBuilder cmdBuilderSell;
        SellHistoryForm sellHistoryForm;

        float exRate = 0;

        public MainForm()
        {
            InitializeComponent();
            // load properties settings
            //try
            //{
            //    numericExchangeRate.Value = (decimal)Properties.Settings.Default.ExRate;
            //}
            //catch
            //{
            //    numericExchangeRate.Value = (decimal)30.0; 
            //}
            //exRate = (float)numericExchangeRate.Value;
            //try
            //{
            //    textBoxDBPath.Text = Properties.Settings.Default.MainDBConnectionString;
            //    LoadDBFile();
            //}
            //catch
            //{
            //    MessageBox.Show("Please specify the Datebase file path in the textbox.");
            //}     
            numericExchangeRate.Value = (decimal)30.0;
            exRate = (float)numericExchangeRate.Value;

            textBoxDBPath.Text = @"C:\programming\BusinessManager\database\TestMainDB.sdf";
            LoadDBFile();
            SellHistoryForm.mainForm = this;
            InventoryListForm.mainForm = this; 

        }

        void FillData()
        {
            //sqlConnection = new SqlCeConnection(Properties.Settings.Default.MainDBConnectionString);
            if ((sqlConnectionInv!= null) && (sqlConnectionInv.State != ConnectionState.Closed))
            {
                sqlConnectionInv.Close(); 
            }
            sqlConnectionInv = new SqlCeConnection("Data Source = " + @textBoxDBPath.Text); //"Data Source=C:\programming\BusinessManager\database\MainDB.sdf");
            // this is for organizing the order of columns in the displayed table, not choosing what to show, every column will be shown no matter if they are selected
            sqlAdapterInv = new SqlCeDataAdapter(
                    "SELECT [Product Name],Quantity, [Purchasing Price],[Current Location],[Purchasing Date],"+
            "[Expiration Date], [Return Date], [Purchasing Place], Notes, [Product ID], Sold FROM Inventory", sqlConnectionInv);
            sqlConnectionInv.Open();
            sqlAdapterInv.Fill(inventoryTable);            
            cmdBuilderInv = new SqlCeCommandBuilder(sqlAdapterInv);

            if ((sqlConnectionSell!=null)&&(sqlConnectionSell.State != ConnectionState.Closed))
            {
                sqlConnectionSell.Close(); 
            }
            sqlConnectionSell = new SqlCeConnection("Data Source = " + @textBoxDBPath.Text);
            // this is for organizing the order of columns in the displayed table, not choosing what to show, every column will be shown no matter if they are selected
            sqlAdapterSell = new SqlCeDataAdapter(
                    "SELECT Products, Paid, Shipped, [Sell ID],[Selling Price], Cost, Cost_TWD, [International Shipping],[InterShipping_TWD]," +
                    "[Domestic Shipping], [Customer Paid Shipping], Profit, Date, Quantity, Notes, [Ready to Ship], [7-11], [7-11 Pay] " +
                    "FROM SellHistory", sqlConnectionSell);
            sqlConnectionSell.Open();
            sqlAdapterSell.Fill(sellHistoryTable);
            cmdBuilderSell = new SqlCeCommandBuilder(sqlAdapterSell);

        }
        private void buttonAddNew_Click(object sender, EventArgs e)
        {
            if (addNewInvForm == null)
            {
                addNewInvForm = new AddNewInventoryForm();
            }

            DataTable tempDT = new DataTable();
            sqlAdapterInv.Fill(tempDT);

            // Create autocomplete collection
            //use LINQ method syntax to pull the Title field from a DT into a string array...
            string[] postSource = tempDT
                                .AsEnumerable()
                                .Select<System.Data.DataRow, String>(x => x.Field<String>("Product Name"))
                                .ToArray();

            var source = new AutoCompleteStringCollection();
            source.AddRange(postSource);
             

            //var source = new AutoCompleteStringCollection();
            //foreach (DataRow row in tempDT.Rows)
            //{
            //    source.Add(row["Product Name"].ToString()); //assuming required data is in first column
            //}


            addNewInvForm.autoCompleteStringCollection = source;

            if (DialogResult.OK == addNewInvForm.ShowDialog())
            {
                DataRow dr;

                dr = inventoryTable.NewRow();
                dr["Product Name"] = addNewInvForm.productName;
                dr["Purchasing Price"] = addNewInvForm.purchasingPrice;
                dr["Quantity"] = addNewInvForm.quantity;
                dr["Expiration Date"] = addNewInvForm.expDate;
                dr["Purchasing Date"] = addNewInvForm.purchasingDate;
                dr["Purchasing Place"] = addNewInvForm.purchasingPlace;
                dr["Return Date"] = addNewInvForm.returnDate;
                dr["Current Location"] = addNewInvForm.currentLocation;
                dr["Notes"] = addNewInvForm.notes;

                inventoryTable.Rows.Add(dr);
                sqlAdapterInv.Update(inventoryTable);
                //inventoryTable.Rows[3].ItemArray[1]
            }
        }
        

        private void buttonSell_Click(object sender, EventArgs e)
        {
            inventoryListForm.formType = InvFormType.sell;
            inventoryListForm.sellHistoryForm = sellHistoryForm; 
            inventoryListForm.Show();
            inventoryListForm.BringToFront();
            inventoryListForm.WindowState = FormWindowState.Maximized;
            inventoryListForm.Form1_Load(new object(), new EventArgs()); 
        }

        private void buttonShowSellHistory_Click(object sender, EventArgs e)
        {
            sellHistoryForm.formType = SellHistFormType.Normal;
            sellHistoryForm.Show();
            sellHistoryForm.WindowState = FormWindowState.Maximized;
            sellHistoryForm.BringToFront();
            sellHistoryForm.SellHistoryForm_Load(new object(), new EventArgs()); 
            
        }

        private void numericExchangeRate_ValueChanged(object sender, EventArgs e)
        {
            exRate = (float)numericExchangeRate.Value;
            inventoryListForm.exRate = exRate;
            sellHistoryForm.exRate = exRate; 
        }

        private void buttonUpdateLocation_Click(object sender, EventArgs e)
        {            
            inventoryListForm.formType = InvFormType.location;
            inventoryListForm.Show();
            inventoryListForm.BringToFront();
            inventoryListForm.WindowState = FormWindowState.Maximized;
            inventoryListForm.Form1_Load(new object(), new EventArgs()); 
        }

        private void buttonBrowseDBFile_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            if (openFileDialog.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                textBoxDBPath.Text = openFileDialog.FileName;
                try
                {                    
                    LoadDBFile();
                }
                catch
                {
                    MessageBox.Show("Please specify the Datebase file path in the textbox.");
                }
            }
        }

        private void LoadDBFile()
        {
            FillData();

            if (inventoryListForm == null)
            {
                inventoryListForm = new InventoryListForm();
            }
            inventoryListForm.sellHistoryForm = sellHistoryForm;
            inventoryListForm.Location = new Point(15, 200);
            inventoryListForm.Text = "Sell";
            inventoryListForm.inventoryTable = inventoryTable;
            inventoryListForm.sellHistoryTable = sellHistoryTable;
            inventoryListForm.sqlAdapterInv = sqlAdapterInv;
            inventoryListForm.sqlAdapterSell = sqlAdapterSell;
            inventoryListForm.exRate = exRate;
            inventoryListForm.formType = InvFormType.sell;

            if (sellHistoryForm == null)
            {
                sellHistoryForm = new SellHistoryForm();
            }
            sellHistoryForm.formType = SellHistFormType.Normal;
            sellHistoryForm.Location = new Point(15, 200);
            sellHistoryForm.exRate = exRate;
            sellHistoryForm.table = sellHistoryTable;
            sellHistoryForm.sqlAdapter = sqlAdapterSell;


        }

        private void MainForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            //save properties settings
            //Properties.Settings.Default.ExRate = (float)numericExchangeRate.Value;
            //Properties.Settings.Default.MainDBConnectionString = textBoxDBPath.Text;
            //Properties.Settings.Default.Save();
        }
    }
}
