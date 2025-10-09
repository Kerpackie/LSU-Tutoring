// See https://aka.ms/new-console-template for more information

using creature_battle_solution;

Console.WriteLine("Welcome to the Creature Battle Arena!");

// 1. Create the creature objects
Dragon smaug = new Dragon("Smaug the Golden", 100, 10, 25);
Goblin grog = new Goblin("Grog the Sneaky", 60, 8, 0.3); // 30% dodge chance

// 2. Start the battle
BattleArena.Fight(smaug, grog);

Console.WriteLine("\nPress any key to exit.");
Console.ReadKey();