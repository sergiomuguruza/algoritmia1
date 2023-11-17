using System;
using System.Windows.Forms;

namespace CalculadoraRectangulo
{
    public partial class FormRectangulo : Form
    {
        public FormRectangulo()
        {
            InitializeComponent();
        }

        private void CalcularButton_Click(object sender, EventArgs e)
        {
            try
            {
                double lado1 = double.Parse(textBoxLado1.Text);
                double lado2 = double.Parse(textBoxLado2.Text);

                double productoLados = lado1 * lado2;
                double raizProducto = Math.Sqrt(productoLados);
                int medidaEnteraSuperior = (int)Math.Ceiling(raizProducto);

                resultadoLabel.Text = $"Raíz cuadrada del producto: {raizProducto:F2}";
                medidaLabel.Text = $"Medida entera superior: {medidaEnteraSuperior}";
            }
            catch (FormatException)
            {
                MessageBox.Show("Ingresa valores numéricos válidos", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
    }
}
