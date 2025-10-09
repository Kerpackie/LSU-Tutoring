namespace creature_battle_solution;

using System;

public class Goblin : Creature
{
    // --- Properties ---
    public double DodgeChance { get; private set; }
    private Random _random = new Random();

    // --- Constructor ---
    public Goblin(string name, int health, int attackPower, double dodgeChance)
        : base(name, health, attackPower)
    {
        // Ensure dodge chance is between 0.0 and 1.0
        DodgeChance = Math.Clamp(dodgeChance, 0.0, 1.0);
    }

    // --- Overridden Method ---

    /// <summary>
    /// Overrides the base TakeDamage method. The Goblin has a chance
    /// to dodge the attack completely.
    /// </summary>
    public override void TakeDamage(int damage)
    {
        if (_random.NextDouble() < DodgeChance)
        {
            Console.WriteLine($"{Name} dodges the attack!");
        }
        else
        {
            // If the dodge fails, call the original base method
            base.TakeDamage(damage);
        }
    }
}