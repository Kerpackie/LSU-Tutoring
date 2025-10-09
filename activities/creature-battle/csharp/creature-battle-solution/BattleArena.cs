namespace creature_battle_solution;

using System;
using System.Threading;

public class BattleArena
{
    /// <summary>
    /// Manages a fight between two creatures until one is defeated.
    /// This method is static because it doesn't need an instance of BattleArena to run.
    /// </summary>
    public static void Fight(Creature c1, Creature c2)
    {
        Console.WriteLine("--- BATTLE START! ---");
        c1.Display();
        c2.Display();
        Console.WriteLine("-----------------------");
        Thread.Sleep(1000); // Pause for drama

        int round = 1;

        // The main battle loop continues as long as both creatures are alive
        while (c1.IsAlive() && c2.IsAlive())
        {
            Console.WriteLine($"\n--- Round {round} ---");

            // Creature 1 attacks Creature 2
            c1.Attack(c2);
            if (!c2.IsAlive()) break; // Check if the defender was defeated

            Thread.Sleep(500);

            // Creature 2 attacks Creature 1
            c2.Attack(c1);
            if (!c1.IsAlive()) break; // Check if the defender was defeated

            Console.WriteLine("\nEnd of Round Status:");
            c1.Display();
            c2.Display();
            Thread.Sleep(1000);
            round++;
        }

        Console.WriteLine("\n--- BATTLE OVER! ---");

        // Determine and announce the winner
        if (c1.IsAlive())
        {
            Console.WriteLine($"{c1.Name} is the victor!");
        }
        else if (c2.IsAlive())
        {
            Console.WriteLine($"{c2.Name} is the victor!");
        }
        else
        {
            Console.WriteLine("Both creatures have been defeated! It's a draw.");
        }
    }
}