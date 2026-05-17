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
            IMyMath myMath = obj;

            // Заголовок приложения
            Console.ForegroundColor = ConsoleColor.Cyan;
            Console.WriteLine("╔══════════════════════════════════════╗");
            Console.WriteLine("║     МАТЕМАТИЧЕСКИЕ ВЫЧИСЛЕНИЯ        ║");
            Console.WriteLine("╚══════════════════════════════════════╝");
            Console.ResetColor();
            Console.WriteLine();

            // Add: сложение двух чисел
            int res = myMath.Add(10, 20);
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.Write("Add(10, 20)");
            Console.ResetColor();
            Console.WriteLine($" => Результат сложения: {res}");
            Console.WriteLine();

            // Fun41: (a + b) / 100
            float result41 = myMath.Fun41(10, 20);
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.Write("Fun41(10, 20)");
            Console.ResetColor();
            Console.WriteLine($" => (a + b) / 100 = {result41:F2}");
            Console.WriteLine();

            // Fun42: площадь круга (π * r²)
            double result42 = myMath.Fun42(12);
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.Write("Fun42(12)");
            Console.ResetColor();
            Console.WriteLine($" => Площадь круга = {result42:F4}");
            Console.WriteLine();

            // Fun43: квадрат числа
            double result43 = myMath.Fun43(122);
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.Write("Fun43(122, [double])");
            Console.ResetColor();
            Console.WriteLine($" => Квадрат числа = {result43}");
            Console.WriteLine();

            // Итоговая черта
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
