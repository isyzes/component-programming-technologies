using System;

namespace CalendarCSharp
{
    internal class Program
    {
        static void Main(string[] args)
        {
            MSACAL.Calendar calendar = new MSACAL.Calendar();

            PrintCalendarInfo(calendar);

            calendar.Day = 31;
            calendar.BackColor = 54;

            PrintCalendarInfo(calendar);
        }

        static void PrintCalendarInfo(MSACAL.Calendar calendar)
        {
            Console.WriteLine($"[Календарь] День: {calendar.Day}, Цвет фона: {calendar.BackColor}");
        }
    }
}
