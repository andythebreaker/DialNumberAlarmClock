using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace threadtest
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            button2.Text =( Int16.Parse(button2.Text) + 1).ToString();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            button1.Text = DateTime.Now.ToString();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Thread thread0 = new Thread(run0);
            thread0.Start();
        }

        public void run0() {
            while (true)
            {
                Console.WriteLine("RLEEPTY~");
                Thread.Sleep(2000);
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Thread thread2 = new Thread(run2);
            thread2.Start();
        }
        public void run2()
        {
            while (true)
            {
                button1.Invoke((MethodInvoker)delegate
                {
                button1.PerformClick();
                });
                Thread.Sleep(800);
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            button1.PerformClick();
        }

        private void label12_Click(object sender, EventArgs e)
        {

        }
    }
}
