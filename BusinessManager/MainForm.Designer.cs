namespace BusinessManager
{
    partial class MainForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.buttonAddNewToInv = new System.Windows.Forms.Button();
            this.buttonSell = new System.Windows.Forms.Button();
            this.buttonShowSellHistory = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.numericExchangeRate = new System.Windows.Forms.NumericUpDown();
            this.label2 = new System.Windows.Forms.Label();
            this.buttonUpdateLocation = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.textBoxDBPath = new System.Windows.Forms.TextBox();
            this.buttonBrowseDBFile = new System.Windows.Forms.Button();
            this.label4 = new System.Windows.Forms.Label();
            this.buttonShowPurchaseHistory = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.numericExchangeRate)).BeginInit();
            this.SuspendLayout();
            // 
            // buttonAddNewToInv
            // 
            this.buttonAddNewToInv.Location = new System.Drawing.Point(12, 12);
            this.buttonAddNewToInv.Name = "buttonAddNewToInv";
            this.buttonAddNewToInv.Size = new System.Drawing.Size(137, 23);
            this.buttonAddNewToInv.TabIndex = 0;
            this.buttonAddNewToInv.Text = "冯展鹏"; //"Add New to Inventory";
            this.buttonAddNewToInv.UseVisualStyleBackColor = true;
            this.buttonAddNewToInv.Click += new System.EventHandler(this.buttonAddNew_Click);
            // 
            // buttonSell
            // 
            this.buttonSell.Location = new System.Drawing.Point(12, 70);
            this.buttonSell.Name = "buttonSell";
            this.buttonSell.Size = new System.Drawing.Size(137, 23);
            this.buttonSell.TabIndex = 2;
            this.buttonSell.Text = "Sell";
            this.buttonSell.UseVisualStyleBackColor = true;
            this.buttonSell.Click += new System.EventHandler(this.buttonSell_Click);
            // 
            // buttonShowSellHistory
            // 
            this.buttonShowSellHistory.Location = new System.Drawing.Point(12, 99);
            this.buttonShowSellHistory.Name = "buttonShowSellHistory";
            this.buttonShowSellHistory.Size = new System.Drawing.Size(137, 23);
            this.buttonShowSellHistory.TabIndex = 3;
            this.buttonShowSellHistory.Text = "Show Sell History";
            this.buttonShowSellHistory.UseVisualStyleBackColor = true;
            this.buttonShowSellHistory.Click += new System.EventHandler(this.buttonShowSellHistory_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 229);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(48, 13);
            this.label1.TabIndex = 4;
            this.label1.Text = "1 USD =";
            // 
            // numericExchangeRate
            // 
            this.numericExchangeRate.DecimalPlaces = 4;
            this.numericExchangeRate.Location = new System.Drawing.Point(64, 227);
            this.numericExchangeRate.Name = "numericExchangeRate";
            this.numericExchangeRate.Size = new System.Drawing.Size(82, 20);
            this.numericExchangeRate.TabIndex = 5;
            this.numericExchangeRate.Value = new decimal(new int[] {
            3267,
            0,
            0,
            131072});
            this.numericExchangeRate.ValueChanged += new System.EventHandler(this.numericExchangeRate_ValueChanged);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(152, 229);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(33, 13);
            this.label2.TabIndex = 6;
            this.label2.Text = "TWD";
            // 
            // buttonUpdateLocation
            // 
            this.buttonUpdateLocation.Location = new System.Drawing.Point(12, 41);
            this.buttonUpdateLocation.Name = "buttonUpdateLocation";
            this.buttonUpdateLocation.Size = new System.Drawing.Size(137, 23);
            this.buttonUpdateLocation.TabIndex = 7;
            this.buttonUpdateLocation.Text = "Update Location";
            this.buttonUpdateLocation.UseVisualStyleBackColor = true;
            this.buttonUpdateLocation.Click += new System.EventHandler(this.buttonUpdateLocation_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(12, 180);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(46, 13);
            this.label3.TabIndex = 8;
            this.label3.Text = "DB path";
            // 
            // textBoxDBPath
            // 
            this.textBoxDBPath.Location = new System.Drawing.Point(64, 180);
            this.textBoxDBPath.Multiline = true;
            this.textBoxDBPath.Name = "textBoxDBPath";
            this.textBoxDBPath.Size = new System.Drawing.Size(192, 35);
            this.textBoxDBPath.TabIndex = 9;
            this.textBoxDBPath.Text = "C:\\programming\\BusinessManager\\database\\TestMainDB.sdf";
            // 
            // buttonBrowseDBFile
            // 
            this.buttonBrowseDBFile.Location = new System.Drawing.Point(256, 180);
            this.buttonBrowseDBFile.Name = "buttonBrowseDBFile";
            this.buttonBrowseDBFile.Size = new System.Drawing.Size(30, 20);
            this.buttonBrowseDBFile.TabIndex = 10;
            this.buttonBrowseDBFile.Text = "...";
            this.buttonBrowseDBFile.UseVisualStyleBackColor = true;
            this.buttonBrowseDBFile.Click += new System.EventHandler(this.buttonBrowseDBFile_Click);
            // 
            // label4
            // 
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.Location = new System.Drawing.Point(165, 12);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(100, 110);
            this.label4.TabIndex = 11;
            this.label4.Text = "Business with Taiwan Partners";
            this.label4.Visible = false;
            // 
            // buttonShowPurchaseHistory
            // 
            this.buttonShowPurchaseHistory.Location = new System.Drawing.Point(12, 128);
            this.buttonShowPurchaseHistory.Name = "buttonShowPurchaseHistory";
            this.buttonShowPurchaseHistory.Size = new System.Drawing.Size(137, 23);
            this.buttonShowPurchaseHistory.TabIndex = 12;
            this.buttonShowPurchaseHistory.Text = "Show Purchase History";
            this.buttonShowPurchaseHistory.UseVisualStyleBackColor = true;
            this.buttonShowPurchaseHistory.Click += new System.EventHandler(this.buttonShowPurchaseHistory_Click);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(309, 266);
            this.Controls.Add(this.buttonShowPurchaseHistory);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.buttonBrowseDBFile);
            this.Controls.Add(this.textBoxDBPath);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.buttonUpdateLocation);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.numericExchangeRate);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.buttonShowSellHistory);
            this.Controls.Add(this.buttonSell);
            this.Controls.Add(this.buttonAddNewToInv);
            this.Name = "MainForm";
            this.Text = "MainForm";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.MainForm_FormClosing);
            ((System.ComponentModel.ISupportInitialize)(this.numericExchangeRate)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.NumericUpDown numericExchangeRate;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox textBoxDBPath;
        private System.Windows.Forms.Button buttonBrowseDBFile;
        public System.Windows.Forms.Button buttonAddNewToInv;
        public System.Windows.Forms.Button buttonSell;
        public System.Windows.Forms.Button buttonShowSellHistory;
        public System.Windows.Forms.Button buttonUpdateLocation;
        private System.Windows.Forms.Label label4;
        public System.Windows.Forms.Button buttonShowPurchaseHistory;
    }
}