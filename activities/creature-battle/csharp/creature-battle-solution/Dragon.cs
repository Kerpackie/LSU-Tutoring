namespace creature_battle_solution;

using System;

public class Dragon : Creature
{
    // --- Properties ---
    public int FireBreathPower { get; private set; }
    private Random _random = new Random(); // For random chance attacks

    // --- Constructor ---
    // Uses ': base(...)' to call the parent Creature constructor
    public Dragon(string name, int health, int attackPower, int fireBreathPower)
        : base(name, health, attackPower)
    {
        FireBreathPower = fireBreathPower;
    }

    // --- Overridden Method ---

    /// <summary>
    /// Overrides the base Attack method. The Dragon has a 50% chance
    /// to breathe fire instead of a regular attack.
    /// </summary>
    public override void Attack(Creature target)
    {
        // 50% chance to use fire breath
        if (_random.Next(0, 2) == 0)
        {
            BreatheFire(target);
        }
        else
        {
            // Calls the original base method
            base.Attack(target);
        }
    }

    // --- New Method ---

    /// <summary>
    /// A special attack unique to the Dragon.
    /// </summary>
    public void BreatheFire(Creature target)
    {
        Console.WriteLine($"{Name} unleashes a torrent of fire on {target.Name}, dealing {FireBreathPower} damage!");
        target.TakeDamage(FireBreathPower);
    }
}