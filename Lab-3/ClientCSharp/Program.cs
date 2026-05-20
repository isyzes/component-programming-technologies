using System;
using System.Runtime.InteropServices;
using AutoSvrLib;

namespace ClientCSharp
{
    internal class Program
    {
        static void Main(string[] args)
        {
            var obj = new MyMath();
            IMyMath pimymath = obj;
            pimymath.Param1 = 6;
            //pimymath.Param2 = 0;
            int res = pimymath.Add(pimymath.Param1, 5);
            int res1 = pimymath.Sub(pimymath.Param1, 5);
            Console.WriteLine(res);
            Console.WriteLine(res1);
            Console.WriteLine(pimymath.Param1);
            IVer pIver = (IVer)pimymath;
            Console.WriteLine(pIver.GetAuthor("Игнатович, gr.40332"));
            Console.ReadLine();
            Marshal.ReleaseComObject(pimymath);
        }

        static void lab3()
        {
            var obj = new MyMath();
            IMyMath myMath = obj;
            IVer pIver = (IVer)myMath;

            Console.WriteLine(pIver.GetAuthor("C#: IGNATOVICH 40332"));

            Console.WriteLine("Welcome, C#: IGNATOVICH 40332");

            //Заголовок приложения
            Console.ForegroundColor = ConsoleColor.Cyan;
            Console.WriteLine("╔══════════════════════════════════════╗");
            Console.WriteLine("║      МАТЕМАТИЧЕСКИЕ ВЫЧИСЛЕНИЯ       ║");
            Console.WriteLine("╚══════════════════════════════════════╝");
            Console.ResetColor();
            Console.WriteLine();

            //Add: сложение двух чисел
            int res = myMath.Add(10, 20);
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.Write("Add(10, 20)");
            Console.ResetColor();
            Console.WriteLine($" => Результат сложения: {res}");
            Console.WriteLine();

            //Sub: вычетание двух чисел
            res = myMath.Sub(50, 10);
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.Write("Sub(50, 10)");
            Console.ResetColor();
            Console.WriteLine($" => Результат вычетания: {res}");
            Console.WriteLine();

            //Fun41: (a + b) / 100
            float result41 = myMath.Fun41(10, 20);
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.Write("Fun41(10, 20)");
            Console.ResetColor();
            Console.WriteLine($" => (a + b) / 100 = {result41:F2}");
            Console.WriteLine();

            //Fun42: площадь круга(π* r²)
            double result42 = myMath.Fun42(12);
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.Write("Fun42(12)");
            Console.ResetColor();
            Console.WriteLine($" => Площадь круга = {result42:F4}");
            Console.WriteLine();

            //Fun43: квадрат числа
            double result43 = 0;
            myMath.Fun43(122, result43);
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.Write("Fun43(122, [double])");
            Console.ResetColor();
            Console.WriteLine($" => Квадрат числа = {result43}");
            Console.WriteLine();

            //Итоговая черта

            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine("╔══════════════════════════════════════╗");
            Console.WriteLine("║   Все вычисления выполнены успешно!  ║");
            Console.WriteLine("╚══════════════════════════════════════╝");
            Console.ResetColor();

            Marshal.ReleaseComObject(myMath);
            Console.WriteLine();
            Console.Write("Нажмите Enter для выхода...");
            Console.ReadLine();
        }
    }
}
