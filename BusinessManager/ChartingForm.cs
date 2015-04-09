using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Windows.Forms.DataVisualization.Charting;

namespace BusinessManager
{
    public partial class ChartingForm : Form
    {
        public ChartingForm()
        {
            InitializeComponent();
        }
        

        public void updateChart(DataTable table, string xName, string[] yNames)
        {
            
            // Set chart data source
            chart1.DataSource = table;
            chart1.Series.Clear();
            //chart1.ChartAreas[0].AxisX.CustomLabels 
            chart1.ChartAreas[0].AxisX.MajorGrid.Interval = 1.0;
            chart1.ChartAreas[0].AxisX.MinorGrid.Interval = 1.0;
            chart1.ChartAreas[0].AxisY.MajorGrid.Interval = 10000.0;
            chart1.ChartAreas[0].AxisY.MinorGrid.Interval = 10000.0;
            
 
            // Set series members names for the X and Y values
            for (int i = 0; i < yNames.Length; i++)
            {
                if (yNames[i] != null)
                {
                    chart1.Series.Add(yNames[i]);
                    chart1.Series[yNames[i]].ChartType = SeriesChartType.Line;
                    chart1.Series[yNames[i]].XValueMember = xName;
                    chart1.Series[yNames[i]].YValueMembers = yNames[i];
                }
            }
 
            // Data bind to the selected data source
            chart1.DataBind();
        }
    }
}
