namespace BusinessManager
{
    partial class AddNewSellForm
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
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.dateTimePickerSellingDate = new System.Windows.Forms.DateTimePicker();
            this.numericQuantity = new System.Windows.Forms.NumericUpDown();
            this.textBoxNotes = new System.Windows.Forms.TextBox();
            this.numericCost = new System.Windows.Forms.NumericUpDown();
            this.textBoxProducts = new System.Windows.Forms.TextBox();
            this.buttonOK = new System.Windows.Forms.Button();
            this.buttonCancel = new System.Windows.Forms.Button();
            this.numericSellingPrice = new System.Windows.Forms.NumericUpDown();
            this.label5 = new System.Windows.Forms.Label();
            this.numericInternationalShipping = new System.Windows.Forms.NumericUpDown();
            this.label1 = new System.Windows.Forms.Label();
            this.numericDomesticShipping = new System.Windows.Forms.NumericUpDown();
            this.label7 = new System.Windows.Forms.Label();
            this.numericCustomerPaidShipping = new System.Windows.Forms.NumericUpDown();
            this.label8 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.textBoxProfit = new System.Windows.Forms.TextBox();
            this.label11 = new System.Windows.Forms.Label();
            this.label12 = new System.Windows.Forms.Label();
            this.label13 = new System.Windows.Forms.Label();
            this.label14 = new System.Windows.Forms.Label();
            this.label15 = new System.Windows.Forms.Label();
            this.checkBoxAddToExist = new System.Windows.Forms.CheckBox();
            ((System.ComponentModel.ISupportInitialize)(this.numericQuantity)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericCost)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericSellingPrice)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericInternationalShipping)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericDomesticShipping)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericCustomerPaidShipping)).BeginInit();
            this.SuspendLayout();
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(12, 17);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(49, 13);
            this.label2.TabIndex = 1;
            this.label2.Text = "Products";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(12, 278);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(28, 13);
            this.label3.TabIndex = 2;
            this.label3.Text = "Cost";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(12, 301);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(46, 13);
            this.label4.TabIndex = 3;
            this.label4.Text = "Quantity";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(12, 327);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(64, 13);
            this.label6.TabIndex = 5;
            this.label6.Text = "Selling Date";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(12, 484);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(35, 13);
            this.label9.TabIndex = 8;
            this.label9.Text = "Notes";
            // 
            // dateTimePickerSellingDate
            // 
            this.dateTimePickerSellingDate.CustomFormat = "MM dd, yy ";
            this.dateTimePickerSellingDate.Format = System.Windows.Forms.DateTimePickerFormat.Short;
            this.dateTimePickerSellingDate.Location = new System.Drawing.Point(134, 322);
            this.dateTimePickerSellingDate.Name = "dateTimePickerSellingDate";
            this.dateTimePickerSellingDate.Size = new System.Drawing.Size(116, 20);
            this.dateTimePickerSellingDate.TabIndex = 10;
            // 
            // numericQuantity
            // 
            this.numericQuantity.Location = new System.Drawing.Point(134, 297);
            this.numericQuantity.Maximum = new decimal(new int[] {
            276447232,
            23283,
            0,
            0});
            this.numericQuantity.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericQuantity.Name = "numericQuantity";
            this.numericQuantity.Size = new System.Drawing.Size(116, 20);
            this.numericQuantity.TabIndex = 12;
            this.numericQuantity.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // textBoxNotes
            // 
            this.textBoxNotes.Location = new System.Drawing.Point(134, 484);
            this.textBoxNotes.Multiline = true;
            this.textBoxNotes.Name = "textBoxNotes";
            this.textBoxNotes.Size = new System.Drawing.Size(186, 52);
            this.textBoxNotes.TabIndex = 13;
            // 
            // numericCost
            // 
            this.numericCost.DecimalPlaces = 2;
            this.numericCost.Location = new System.Drawing.Point(134, 272);
            this.numericCost.Maximum = new decimal(new int[] {
            276447232,
            23283,
            0,
            0});
            this.numericCost.Name = "numericCost";
            this.numericCost.Size = new System.Drawing.Size(116, 20);
            this.numericCost.TabIndex = 15;
            this.numericCost.ValueChanged += new System.EventHandler(this.AnyCost_ValueChanged);
            // 
            // textBoxProducts
            // 
            this.textBoxProducts.Location = new System.Drawing.Point(134, 12);
            this.textBoxProducts.Multiline = true;
            this.textBoxProducts.Name = "textBoxProducts";
            this.textBoxProducts.Size = new System.Drawing.Size(186, 254);
            this.textBoxProducts.TabIndex = 16;
            // 
            // buttonOK
            // 
            this.buttonOK.Location = new System.Drawing.Point(72, 582);
            this.buttonOK.Name = "buttonOK";
            this.buttonOK.Size = new System.Drawing.Size(75, 23);
            this.buttonOK.TabIndex = 17;
            this.buttonOK.Text = "OK";
            this.buttonOK.UseVisualStyleBackColor = true;
            this.buttonOK.Click += new System.EventHandler(this.buttonOK_Click);
            // 
            // buttonCancel
            // 
            this.buttonCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.buttonCancel.Location = new System.Drawing.Point(164, 582);
            this.buttonCancel.Name = "buttonCancel";
            this.buttonCancel.Size = new System.Drawing.Size(75, 23);
            this.buttonCancel.TabIndex = 18;
            this.buttonCancel.Text = "Cancel";
            this.buttonCancel.UseVisualStyleBackColor = true;
            this.buttonCancel.Click += new System.EventHandler(this.buttonCancel_Click);
            // 
            // numericSellingPrice
            // 
            this.numericSellingPrice.DecimalPlaces = 2;
            this.numericSellingPrice.Location = new System.Drawing.Point(134, 346);
            this.numericSellingPrice.Maximum = new decimal(new int[] {
            276447232,
            23283,
            0,
            0});
            this.numericSellingPrice.Name = "numericSellingPrice";
            this.numericSellingPrice.Size = new System.Drawing.Size(116, 20);
            this.numericSellingPrice.TabIndex = 22;
            this.numericSellingPrice.ValueChanged += new System.EventHandler(this.AnyCost_ValueChanged);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(12, 350);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(65, 13);
            this.label5.TabIndex = 21;
            this.label5.Text = "Selling Price";
            // 
            // numericInternationalShipping
            // 
            this.numericInternationalShipping.DecimalPlaces = 2;
            this.numericInternationalShipping.Location = new System.Drawing.Point(134, 370);
            this.numericInternationalShipping.Maximum = new decimal(new int[] {
            276447232,
            23283,
            0,
            0});
            this.numericInternationalShipping.Name = "numericInternationalShipping";
            this.numericInternationalShipping.Size = new System.Drawing.Size(116, 20);
            this.numericInternationalShipping.TabIndex = 24;
            this.numericInternationalShipping.ValueChanged += new System.EventHandler(this.AnyCost_ValueChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 373);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(109, 13);
            this.label1.TabIndex = 23;
            this.label1.Text = "International Shipping";
            // 
            // numericDomesticShipping
            // 
            this.numericDomesticShipping.DecimalPlaces = 2;
            this.numericDomesticShipping.Location = new System.Drawing.Point(134, 395);
            this.numericDomesticShipping.Maximum = new decimal(new int[] {
            276447232,
            23283,
            0,
            0});
            this.numericDomesticShipping.Name = "numericDomesticShipping";
            this.numericDomesticShipping.Size = new System.Drawing.Size(116, 20);
            this.numericDomesticShipping.TabIndex = 26;
            this.numericDomesticShipping.ValueChanged += new System.EventHandler(this.AnyCost_ValueChanged);
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(12, 398);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(95, 13);
            this.label7.TabIndex = 25;
            this.label7.Text = "Domestic Shipping";
            // 
            // numericCustomerPaidShipping
            // 
            this.numericCustomerPaidShipping.DecimalPlaces = 2;
            this.numericCustomerPaidShipping.Location = new System.Drawing.Point(134, 420);
            this.numericCustomerPaidShipping.Maximum = new decimal(new int[] {
            276447232,
            23283,
            0,
            0});
            this.numericCustomerPaidShipping.Name = "numericCustomerPaidShipping";
            this.numericCustomerPaidShipping.Size = new System.Drawing.Size(116, 20);
            this.numericCustomerPaidShipping.TabIndex = 28;
            this.numericCustomerPaidShipping.ValueChanged += new System.EventHandler(this.AnyCost_ValueChanged);
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(12, 423);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(119, 13);
            this.label8.TabIndex = 27;
            this.label8.Text = "Customer Paid Shipping";
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(12, 447);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(31, 13);
            this.label10.TabIndex = 29;
            this.label10.Text = "Profit";
            // 
            // textBoxProfit
            // 
            this.textBoxProfit.Location = new System.Drawing.Point(134, 447);
            this.textBoxProfit.Name = "textBoxProfit";
            this.textBoxProfit.ReadOnly = true;
            this.textBoxProfit.Size = new System.Drawing.Size(116, 20);
            this.textBoxProfit.TabIndex = 30;
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(256, 274);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(30, 13);
            this.label11.TabIndex = 31;
            this.label11.Text = "USD";
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Location = new System.Drawing.Point(256, 373);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(30, 13);
            this.label12.TabIndex = 32;
            this.label12.Text = "USD";
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Location = new System.Drawing.Point(256, 398);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(33, 13);
            this.label13.TabIndex = 33;
            this.label13.Text = "TWD";
            // 
            // label14
            // 
            this.label14.AutoSize = true;
            this.label14.Location = new System.Drawing.Point(256, 423);
            this.label14.Name = "label14";
            this.label14.Size = new System.Drawing.Size(33, 13);
            this.label14.TabIndex = 34;
            this.label14.Text = "TWD";
            // 
            // label15
            // 
            this.label15.AutoSize = true;
            this.label15.Location = new System.Drawing.Point(256, 450);
            this.label15.Name = "label15";
            this.label15.Size = new System.Drawing.Size(33, 13);
            this.label15.TabIndex = 35;
            this.label15.Text = "TWD";
            // 
            // checkBoxAddToExist
            // 
            this.checkBoxAddToExist.AutoSize = true;
            this.checkBoxAddToExist.Location = new System.Drawing.Point(14, 551);
            this.checkBoxAddToExist.Name = "checkBoxAddToExist";
            this.checkBoxAddToExist.Size = new System.Drawing.Size(123, 17);
            this.checkBoxAddToExist.TabIndex = 36;
            this.checkBoxAddToExist.Text = "Add To Existing Item";
            this.checkBoxAddToExist.UseVisualStyleBackColor = true;
            this.checkBoxAddToExist.CheckedChanged += new System.EventHandler(this.checkBoxAddToExist_CheckedChanged);
            // 
            // AddNewSellForm
            // 
            this.AcceptButton = this.buttonOK;
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.CancelButton = this.buttonCancel;
            this.ClientSize = new System.Drawing.Size(346, 625);
            this.Controls.Add(this.checkBoxAddToExist);
            this.Controls.Add(this.label15);
            this.Controls.Add(this.label14);
            this.Controls.Add(this.label13);
            this.Controls.Add(this.label12);
            this.Controls.Add(this.label11);
            this.Controls.Add(this.textBoxProfit);
            this.Controls.Add(this.label10);
            this.Controls.Add(this.numericCustomerPaidShipping);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.numericDomesticShipping);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.numericInternationalShipping);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.numericSellingPrice);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.buttonCancel);
            this.Controls.Add(this.buttonOK);
            this.Controls.Add(this.textBoxProducts);
            this.Controls.Add(this.numericCost);
            this.Controls.Add(this.textBoxNotes);
            this.Controls.Add(this.numericQuantity);
            this.Controls.Add(this.dateTimePickerSellingDate);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Name = "AddNewSellForm";
            this.Text = "Add New";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.AddNewSellForm_FormClosing);
            this.Load += new System.EventHandler(this.AddNewSellForm_Load);
            ((System.ComponentModel.ISupportInitialize)(this.numericQuantity)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericCost)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericSellingPrice)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericInternationalShipping)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericDomesticShipping)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericCustomerPaidShipping)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.DateTimePicker dateTimePickerSellingDate;
        private System.Windows.Forms.NumericUpDown numericQuantity;
        private System.Windows.Forms.TextBox textBoxNotes;
        private System.Windows.Forms.NumericUpDown numericCost;
        private System.Windows.Forms.TextBox textBoxProducts;
        private System.Windows.Forms.Button buttonOK;
        private System.Windows.Forms.Button buttonCancel;
        private System.Windows.Forms.NumericUpDown numericSellingPrice;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.NumericUpDown numericInternationalShipping;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.NumericUpDown numericDomesticShipping;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.NumericUpDown numericCustomerPaidShipping;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.TextBox textBoxProfit;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.Label label14;
        private System.Windows.Forms.Label label15;
        private System.Windows.Forms.CheckBox checkBoxAddToExist;
    }
}