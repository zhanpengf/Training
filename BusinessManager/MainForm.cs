﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Data.SqlClient;

namespace BusinessManager
{

    public partial class MainForm : Form
    {
		public static String connectionString = "Data Source=127.0.0.1,1433;" +
			"database=master;" +
			"User id=SA;" +
			"Password=Lola@2467;";
        
        public static void submitQuery(string queryString, ref DataTable dataTable, SqlDataAdapter sqlAdapter)
		{
			using (SqlConnection sqlConnection = new SqlConnection(MainForm.connectionString))
			{
                dataTable.Clear();
				SqlCommand cmd = new SqlCommand(queryString, sqlConnection);
				sqlAdapter.SelectCommand = cmd;
                sqlAdapter.Fill(dataTable);
			}
		}

        public static void updateGridViewWithTable(ref DataGridView dataGridView, DataTable dataTable)
        {
			BindingSource bs = new BindingSource();
			bs.DataSource = dataTable;
			dataGridView.DataSource = bs;
        }

        SqlConnection sqlConnectionInv;
        SqlDataAdapter sqlAdapterInv;
        DataTable inventoryTable =new DataTable();        
        SqlCommandBuilder cmdBuilderInv;
        AddNewInventoryForm addNewInvForm;
        InventoryListForm inventoryListForm;

        SqlConnection sqlConnectionSell;
        SqlDataAdapter sqlAdapterSell;
        DataTable sellHistoryTable = new DataTable(); 
        SqlCommandBuilder cmdBuilderSell;
        SellHistoryForm sellHistoryForm;

        SqlConnection sqlConnectionPurchase;
        SqlDataAdapter sqlAdapterPurchase;
        DataTable purchaseHistoryTable = new DataTable();
        SqlCommandBuilder cmdBuilderPurchase;
        PurchaseHistoryForm purchaseHistoryForm;

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
            //numericExchangeRate.Value = (decimal)30.0;
            exRate = (float)numericExchangeRate.Value;

            //textBoxDBPath.Text = @"C:\Dropbox\BusinessManager\DB2\MainDB.sdf";
            //textBoxDBPath.Text = @"C:\programming\Training\BusinessManager\database\MainDB.sdf";

            try
            {
                LoadDBFile();
            }
			catch (Exception ex)
			{
				MessageBox.Show(ex.ToString());
			}
            SellHistoryForm.mainForm = this;
            InventoryListForm.mainForm = this; 

        }

        void FillData()
        {
            //sqlConnection = new SqlConnection(Properties.Settings.Default.MainDBConnectionString);
            if ((sqlConnectionInv!= null) && (sqlConnectionInv.State != ConnectionState.Closed))
            {
                sqlConnectionInv.Close(); 
            }

            sqlConnectionInv = new SqlConnection(connectionString);

            // this is for organizing the order of columns in the displayed table, not choosing what to show, every column will be shown no matter if they are selected
            sqlAdapterInv = new SqlDataAdapter(
                    "SELECT [Product Name],Quantity, [Purchasing Price],[Current Location],[Purchasing Date],"+
            "[Expiration Date], [Return Date], [Purchasing Place], Notes, [Product ID], Sold FROM Inventory", sqlConnectionInv);
            sqlConnectionInv.Open();
            sqlAdapterInv.Fill(inventoryTable);            
            cmdBuilderInv = new SqlCommandBuilder(sqlAdapterInv);

            if ((sqlConnectionSell!=null)&&(sqlConnectionSell.State != ConnectionState.Closed))
            {
                sqlConnectionSell.Close(); 
            }
            sqlConnectionSell = new SqlConnection(connectionString);
            // this is for organizing the order of columns in the displayed table, not choosing what to show, every column will be shown no matter if they are selected
            sqlAdapterSell = new SqlDataAdapter(
                    "SELECT Products, Paid, Shipped, [7-11], [Sell ID],[Selling Price], Cost, Cost_TWD, [International Shipping],[InterShipping_TWD]," +
                    "[Domestic Shipping], [Customer Paid Shipping], Profit, Date, Quantity, Notes, [Ready to Ship], [7-11 Pay] " +
                    "FROM SellHistory", sqlConnectionSell);
            sqlConnectionSell.Open();
            sqlAdapterSell.Fill(sellHistoryTable);
            cmdBuilderSell = new SqlCommandBuilder(sqlAdapterSell);

            if ((sqlConnectionPurchase != null) && (sqlConnectionPurchase.State != ConnectionState.Closed))
            {
                sqlConnectionPurchase.Close();
            }
            sqlConnectionPurchase = new SqlConnection(connectionString);
			// this is for organizing the order of columns in the displayed table, not choosing what to show, every column will be shown no matter if they are selected
			sqlAdapterPurchase = new SqlDataAdapter(
			        "SELECT [Product Name],Quantity, [Purchasing Price],[Current Location],[Purchasing Date]," +
			"[Expiration Date], [Return Date], [Purchasing Place], Notes, [Product ID], Sold FROM PurchaseHistory", sqlConnectionPurchase);
			sqlConnectionPurchase.Open();
			sqlAdapterPurchase.Fill(purchaseHistoryTable);
            cmdBuilderPurchase = new SqlCommandBuilder(sqlAdapterPurchase);
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

                DataRow dr2 = purchaseHistoryTable.NewRow();
                //dr2.ItemArray = dr.ItemArray.Clone() as object[];
                dr2["Product Name"] = addNewInvForm.productName;
                dr2["Purchasing Price"] = addNewInvForm.purchasingPrice;
                dr2["Quantity"] = addNewInvForm.quantity;
                dr2["Expiration Date"] = addNewInvForm.expDate;
                dr2["Purchasing Date"] = addNewInvForm.purchasingDate;
                dr2["Purchasing Place"] = addNewInvForm.purchasingPlace;
                dr2["Return Date"] = addNewInvForm.returnDate;
                dr2["Current Location"] = addNewInvForm.currentLocation;
                dr2["Notes"] = addNewInvForm.notes;
                purchaseHistoryTable.Rows.Add(dr2);
                sqlAdapterPurchase.Update(purchaseHistoryTable); 
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
            sellHistoryForm.sellHistoryTable = sellHistoryTable;
            sellHistoryForm.sqlAdapter = sqlAdapterSell;
            sellHistoryForm.sqlAdapterPurchase = sqlAdapterPurchase;
            sellHistoryForm.purchaseHistoryTable = purchaseHistoryTable; 

            if (purchaseHistoryForm == null)
            {
                purchaseHistoryForm = new PurchaseHistoryForm(); 
            }
            purchaseHistoryForm.purchaseHistoryTable = purchaseHistoryTable;
            purchaseHistoryForm.sellHistoryForm = sellHistoryForm;
            purchaseHistoryForm.Location = new Point(15, 200);
            purchaseHistoryForm.Text = "Purchase History";
            purchaseHistoryForm.inventoryTable = inventoryTable;
            purchaseHistoryForm.sellHistoryTable = sellHistoryTable;
            purchaseHistoryForm.sqlAdapterInv = sqlAdapterInv;
            purchaseHistoryForm.sqlAdapterSell = sqlAdapterSell;
            purchaseHistoryForm.sqlAdapterPurchase = sqlAdapterPurchase;
            purchaseHistoryForm.exRate = exRate;
        }

        private void MainForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            //save properties settings
            //Properties.Settings.Default.ExRate = (float)numericExchangeRate.Value;
            //Properties.Settings.Default.MainDBConnectionString = textBoxDBPath.Text;
            //Properties.Settings.Default.Save();
        }

        private void buttonShowPurchaseHistory_Click(object sender, EventArgs e)
        {
            purchaseHistoryForm.sellHistoryForm = sellHistoryForm;
            purchaseHistoryForm.Show();
            purchaseHistoryForm.BringToFront();
            purchaseHistoryForm.WindowState = FormWindowState.Maximized;
            //purchaseHistoryForm.Form1_Load(new object(), new EventArgs()); 
        }
    }
}
