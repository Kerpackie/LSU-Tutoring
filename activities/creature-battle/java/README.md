## Exercise: Creature Battle Arena

This project involves creating a base `Creature` class and then specializing it into different types, like a `Dragon` and a `Goblin`. Finally, you'll create a `BattleArena` to make them fight\!

### Step 1: Create the Base `Creature` Class

First, let's create the foundation for all our creatures. This class will hold the common attributes and behaviors.

**Instructions:**
Create a Class named `Creature`. It should have the following:

  * **Attributes (Fields/Properties):**
      * `name` (String): The creature's name.
      * `health` (int): Its current health points.
      * `attackPower` (int): How much damage it deals.
  * **Constructor:**
      * A constructor that accepts `name`, `health`, and `attackPower` to initialize the object.
  * **Methods:**
      * `attack(Creature target)`: This method should reduce the `target` creature's health by the `attackPower` of the current creature. Print a message describing the attack (e.g., "Grog the Goblin attacks, dealing 5 damage\!").
      * `takeDamage(int damage)`: Reduces the creature's `health` by the `damage` amount.
      * `isAlive()`: Returns `true` if `health` is greater than 0, otherwise `false`.
      * `display()`: Prints the creature's status (e.g., "Name: Grog, Health: 15/20, Attack: 5"). You might want to add a `maxHealth` attribute to make this display more informative\!

-----

### Step 2: Create Specialized Creatures using Inheritance

Now, let's create some more interesting creatures that **inherit** from `Creature`. They will have their own unique abilities. This is the core of the inheritance lesson.

**Instructions:**

1.  **Create a `Dragon` class:**
      * It should **extend** `Creature`.
      * Add a new attribute: `fireBreathPower` (int).
      * Create a constructor that accepts `name`, `health`, `attackPower`, and `fireBreathPower`. It must call the parent constructor using `super()`.
      * **Override** the `attack(Creature target)` method. A Dragon's attack should be its regular `attackPower` plus a random chance to use fire breath. (There is a Random() method you can use!)
      * Add a new method `breatheFire(Creature target)` that deals `fireBreathPower` damage.


2.  **Create a `Goblin` class:**
      * It should **extend** `Creature`.
      * Add a new attribute: `dodgeChance` (double, e.g., 0.3 for 30%).
      * Create a constructor that calls the parent `super()` constructor.
      * **Override** the `takeDamage(int damage)` method. The Goblin should have a chance to dodge the attack. If it dodges, it takes no damage. Otherwise, it takes damage as normal.


-----

### Step 3: Create a `BattleArena` Utility Class

This class isn't a creature; it's a "manager" or "utility" class. Its job is to control the battle. This teaches the concept of using methods outside the entity classes themselves.

**Instructions:**
Create a `BattleArena` class with a **static** method. Static methods are perfect for utility functions that don't rely on an object's state.

  * **Method:**
      * `public static void fight(Creature c1, Creature c2)`: This method will contain the main battle loop.
          * The loop should continue as long as **both** creatures `isAlive()`.
          * Inside the loop, `c1` attacks `c2`, then `c2` attacks `c1`.
          * After each attack, check if the defending creature is still alive. If not, break the loop.
          * Display the status of both creatures at the end of each round.
          * After the loop ends, declare the winner\! 

-----

### Step 4: Putting It All Together (The `main` Method)

Finally, create a `Main` class to start the program, create creature objects, and begin the fight.

**Instructions:**
Create a class `Main` with a `main` method.

1.  **Create objects:**
      * Instantiate a `Dragon` object.
      * Instantiate a `Goblin` object.
2.  **Start the battle:**
      * Call the static `fight` method from your `BattleArena` class, passing in the two creatures you just created.
  
  <img width="575" height="583" alt="Screenshot 2025-10-09 at 21 40 59" src="https://github.com/user-attachments/assets/a4bdc4af-2378-4f75-b65d-2b9c8573e3fb" />
      
