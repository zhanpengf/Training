using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace BusinessManager
{
    public partial class AddNewInventoryForm : Form
    {
        public string productName;
        public float purchasingPrice;
        public int quantity;
        public DateTime expDate;
        public DateTime purchasingDate;
        public string purchasingPlace;
        public DateTime returnDate;
        public string currentLocation;
        public string notes;
        public AutoCompleteStringCollection autoCompleteStringCollection = new AutoCompleteStringCollection();

        public AddNewInventoryForm()
        {
            InitializeComponent();
        }

        private void buttonOK_Click(object sender, EventArgs e)
        {
            productName = textBoxProductName.Text;
            purchasingPrice = (float)numericPurchasingPrice.Value;
            quantity = (int)numericQuantity.Value;
            expDate = dateTimePickerExpDate.Value;
            purchasingDate = dateTimePickerPurchasingDate.Value;
            purchasingPlace = textBoxPurchasingPlace.Text;
            if (dateTimePickerReturnDate.Checked)
            {
                returnDate = dateTimePickerReturnDate.Value;
            }
            else
            {
                returnDate = new DateTime(1900,1,1);
            }
            currentLocation = comboBoxCurrentLocation.Text;
            notes = textBoxNotes.Text;
            if (quantity > 0)
            {
                DialogResult = System.Windows.Forms.DialogResult.OK;
                Close();
            }
            else
            {
                MessageBox.Show("Quantity must be > 0.", "", MessageBoxButtons.OK, MessageBoxIcon.Error); 

            }
        }

        private void buttonCancel_Click(object sender, EventArgs e)
        {
            DialogResult = System.Windows.Forms.DialogResult.Cancel;
            Close();
        }

        private void AddNewInventoryForm_Load(object sender, EventArgs e)
        {
            textBoxProductName.AutoCompleteCustomSource = autoCompleteStringCollection;
        }

        private void AddNewInventoryForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            //this.Hide();
            //e.Cancel = true; // this cancels the close event.
        }
    }
}
