using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using Word = Microsoft.Office.Interop.Word;
using Excel = Microsoft.Office.Interop.Excel;

namespace ClientCSharpLate
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Type objType = Type.GetTypeFromProgID("Lb3AutoSvr.MyMath.1");
            dynamic objMath = Activator.CreateInstance(objType);
            int res = objMath.Add(8, 2);
            Console.WriteLine("Результат 8+2=" + res);
            Console.ReadLine();
        }
        static void WordExcel()
        {
            //////////////////////////////
            // Создаем новое приложение Word
            Word.Application wordApp = new Word.Application();
            // Создаем новый документ
            Word.Document document = wordApp.Documents.Add();
            //не отображаем окно Word
            wordApp.Visible = false;
            Console.WriteLine(("Document is creaded, Type a key "));
            Console.ReadLine();
            // Добавляем текст в документ
            document.Content.Text = "Привет, мир таинственной и вездесущей COM!";
            // Отображаем Word
            wordApp.Visible = true;
            Console.WriteLine("Document is shown");
            Console.WriteLine("To hide it - press a key ");
            Console.ReadLine();
            wordApp.Visible = false;
            // Добавляем текст
            document.Content.InsertAfter(" Вот простой пример использования Interop сборок");
            Console.WriteLine("Text2 аdded, to show it - press a key");
            Console.ReadLine();
            wordApp.Visible = true;
            Console.WriteLine("To Add Text3 - press a key");
            Console.ReadLine();
            document.Content.InsertAfter(" в .NET для взаимодействия с COM объектом.");
            Console.WriteLine("To Release a resources, type a key");
            Console.ReadLine();
            document.Close(0, 0, false);
            wordApp.Quit(0, 0, false);
            Marshal.ReleaseComObject(document);
            Marshal.ReleaseComObject(wordApp);


            // Создаем новое приложение Excel
            Console.WriteLine(("To Create a Excel - press a key"));
            Console.ReadLine();
            Excel.Application excelApp = new Excel.Application();
            // Создаем новую книгу
            Excel.Workbook workbook = excelApp.Workbooks.Add();
            // Получаем первый лист
            Excel.Worksheet worksheet = workbook.Worksheets[1];
            // Записываем текст в первую ячейку листа
            worksheet.Cells[1, 1] = "Привет, мир таинственной и вездесущей COM!";
            // Отображаем приложение Excel
            excelApp.Visible = true;
            Console.WriteLine("To Close a Excel - press a key");
            Console.ReadLine();
            // excelApp.Visible = false;
            workbook.Close(false, 0, false);
            excelApp.Quit();
            // Уменьшаем счетчики ссылок объектов
            // СОМ собственного кода
            Marshal.ReleaseComObject(worksheet);
            Marshal.ReleaseComObject(workbook);
            Marshal.ReleaseComObject(excelApp);
            /////////////////////////////////
        }
    }
}
