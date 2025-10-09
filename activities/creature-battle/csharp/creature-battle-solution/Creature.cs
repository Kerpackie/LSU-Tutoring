namespace creature_battle_solution;

public class Creature
{
    // --- Properties ---
    public string Name { get; protected set; }
    public int Health { get; protected set; }
    public int MaxHealth { get; protected set; } // Added for a better display
    public int AttackPower { get; protected set; }

    // --- Constructor ---
    public Creature(string name, int health, int attackPower)
    {
        Name = name;
        MaxHealth = health;
        Health = health;
        AttackPower = attackPower;
    }

    // --- Methods ---

    /// <summary>
    /// Attacks a target creature. Marked as virtual to be overridden by child classes.
    /// </summary>
    /// <param name="target">The creature to attack.</param>
    public virtual void Attack(Creature target)
    {
        Console.WriteLine($"{Name} attacks {target.Name}, dealing {AttackPower} damage!");
        target.TakeDamage(AttackPower);
    }

    /// <summary>
    /// Reduces the creature's health by a specified amount.
    /// Marked as virtual to be overridden by child classes (like Goblin).
    /// </summary>
    /// <param name="damage">The amount of damage to take.</param>
    public virtual void TakeDamage(int damage)
    {
        Health -= damage;
        if (Health < 0)
        {
            Health = 0;
        }
    }

    /// <summary>
    /// Checks if the creature is still alive.
    /// </summary>
    /// <returns>True if health is greater than 0, otherwise false.</returns>
    public bool IsAlive()
    {
        return Health > 0;
    }

    /// <summary>
    /// Displays the current status of the creature.
    /// </summary>
    public void Display()
    {
        Console.WriteLine($"  - {Name}: {Health}/{MaxHealth} HP | Atk: {AttackPower}");
    }
}