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

### Step 1: Create the Base `Creature` Class

(*We’ll build this file progressively, adding fields and methods step-by-step.*)

**1.1 — Create the file and class**

```java
package org.example;

public class Creature {
}
```


**Why?** This establishes the type we’ll enhance. Keep the package line if you’re using packages.


**1.2 — Add the core fields**

```java
package org.example;

public class Creature {
    String name;
    int health;
    int attackPower;
}
```


**Why?** These are the shared stats every creature needs: a `name`, how much life it has (`health`), and how hard it hits (`attackPower`).


**1.3 — Add the constructor**

```java
package org.example;

public class Creature {
    String name;
    int health;
    int attackPower;

    public Creature(String name, int health, int attackPower) {
        this.name = name;
        this.health = health;
        this.attackPower = attackPower;
    }
}
```


**Why?** Constructors guarantee each creature starts with valid values. You pass them in when creating an instance.


**1.4 — Add essential methods (`takeDamage`, `isAlive`, `display`)**

```java
package org.example;

public class Creature {
    String name;
    int health;
    int attackPower;

    public Creature(String name, int health, int attackPower) {
        this.name = name;
        this.health = health;
        this.attackPower = attackPower;
    }

    public void takeDamage(int damage) {
        this.health -= damage;
        if (this.health < 0) this.health = 0;
        System.out.println(this.name + " takes " + damage + " damage. (Health: " + this.health + ")");
    }

    public boolean isAlive() {
        return this.health > 0;
    }

    public void display() {
        System.out.println("Name: " + this.name + ", Health: " + this.health + ", Attack: " + this.attackPower);
    }
}
```


**What’s happening?**  
- `takeDamage`: central place that reduces health and clamps at 0 (no negatives).  
- `isAlive`: tiny helper the battle loop can read — very expressive.  
- `display`: prints a human-readable status for learning and debugging.


**1.5 — Add the basic `attack` behavior**

```java
package org.example;

public class Creature {
    String name;
    int health;
    int attackPower;

    public Creature(String name, int health, int attackPower) {
        this.name = name;
        this.health = health;
        this.attackPower = attackPower;
    }

    public void attack(Creature target) {
        System.out.println(this.name + " attacks " + target.name + ", dealing " + this.attackPower + " damage!");
        target.takeDamage(this.attackPower);
    }

    public void takeDamage(int damage) {
        this.health -= damage;
        if (this.health < 0) this.health = 0;
        System.out.println(this.name + " takes " + damage + " damage. (Health: " + this.health + ")");
    }

    public boolean isAlive() {
        return this.health > 0;
    }

    public void display() {
        System.out.println("Name: " + this.name + ", Health: " + this.health + ", Attack: " + this.attackPower);
    }
}
```


**Why last?** We now have `takeDamage`, so `attack` can simply call it. Keeping damage application in `takeDamage` lets subclasses tweak defense without changing attacks.


-----

### Step 2: Create Specialized Creatures using Inheritance

We’ll build each subclass in small steps so you can see how inheritance and overriding work.

#### 2A) `Dragon`

**2A.1 — Create the subclass**

```java
package org.example;

public class Dragon extends Creature {
}
```


**Why?** `Dragon` **extends** `Creature`, meaning it inherits all fields and methods — we only add what makes dragons unique.


**2A.2 — Add special field and constructor**

```java
package org.example;

import java.util.Random;

public class Dragon extends Creature {
    int fireBreathPower;
    Random rng = new Random();

    public Dragon(String name, int health, int attackPower, int fireBreathPower) {
        super(name, health, attackPower);
        this.fireBreathPower = fireBreathPower;
    }
}
```


**Note:** We call `super(...)` to initialize the inherited `Creature` fields. `fireBreathPower` is a dragon-only stat.


**2A.3 — Override `attack` and add `breatheFire`**

```java
package org.example;

import java.util.Random;

public class Dragon extends Creature {
    int fireBreathPower;
    Random rng = new Random();

    public Dragon(String name, int health, int attackPower, int fireBreathPower) {
        super(name, health, attackPower);
        this.fireBreathPower = fireBreathPower;
    }

    @Override
    public void attack(Creature target) {
        // 50% chance to breathe fire, otherwise normal attack
        if (rng.nextBoolean()) {
            breatheFire(target);
        } else {
            super.attack(target);
        }
    }

    public void breatheFire(Creature target) {
        System.out.println(this.name + " breathes fire for " + fireBreathPower + " damage!");
        target.takeDamage(fireBreathPower);
    }
}
```


**What changed?**  
- Overriding `attack` shows **polymorphism**: a `Dragon` can behave differently than a plain `Creature`.  
- `breatheFire` cleanly encapsulates the special move, keeping code readable.


#### 2B) `Goblin`

**2B.1 — Create the subclass**

```java
package org.example;

public class Goblin extends Creature {
}
```


**Why?** Same inheritance idea: `Goblin` starts as a `Creature` and gains unique defense behavior.


**2B.2 — Add field and constructor**

```java
package org.example;

public class Goblin extends Creature {
    double dodgeChance; // e.g., 0.3 = 30%

    public Goblin(String name, int health, int attackPower, double dodgeChance) {
        super(name, health, attackPower);
        this.dodgeChance = dodgeChance;
    }
}
```


**Tip:** `dodgeChance` is a probability like `0.3` for 30%. We store it on the goblin so each one can feel different.


**2B.3 — Override `takeDamage` to add dodging**

```java
package org.example;

public class Goblin extends Creature {
    double dodgeChance; // e.g., 0.3 = 30%

    public Goblin(String name, int health, int attackPower, double dodgeChance) {
        super(name, health, attackPower);
        this.dodgeChance = dodgeChance;
    }

    @Override
    public void takeDamage(int damage) {
        if (Math.random() < this.dodgeChance) {
            System.out.println(this.name + " dodges the attack!");
            return;
        }
        super.takeDamage(damage);
    }
}
```


**What changed?**  
- We override **defense** rather than **attack**. The rest of the system doesn’t need to know — calls to `attack(...)` still work, and polymorphism handles the dodge.


-----

### Step 3: Create a `BattleArena` Utility Class

We’ll start with a shell and add the battle loop.

**3.1 — Create the class**

```java
package org.example;

public class BattleArena {
}
```

**3.2 — Add the `fight` loop**

```java
package org.example;

public class BattleArena {
    public static void fight(Creature creature1, Creature creature2) {
        int round = 1;
        while (creature1.isAlive() && creature2.isAlive()) {
            System.out.println("Round " + round);
            creature1.attack(creature2);
            if (!creature2.isAlive()) break;
            creature2.attack(creature1);
            creature1.display();
            creature2.display();
            System.out.println();
            round++;
        }

        if (creature1.isAlive() && !creature2.isAlive()) {
            System.out.println(creature2.name + " has fallen!");
            System.out.println("Winner: " + creature1.name + "!");
        } else if (!creature1.isAlive() && creature2.isAlive()) {
            System.out.println(creature1.name + " has fallen!");
            System.out.println("Winner: " + creature2.name + "!");
        } else {
            System.out.println("Both creatures have fallen!");
        }
    }
}
```


**How it works:**  
- The loop runs while **both** creatures are alive.  
- We alternate attacks, print status, and stop when one falls.  
- Declaring winners at the end makes results clear for learners.


-----

### Step 4: Putting It All Together (The `main` Method)

We’ll create the entry point and wire everything up.

**4.1 — Create the class with `main`**

```java
package org.example;

public class Main {
    public static void main(String[] args) {
        // We'll add code here in the next step
    }
}
```

**4.2 — Instantiate creatures and start the fight**

```java
package org.example;

public class Main {
    public static void main(String[] args) {
        Creature smaug = new Dragon("Smaug the Dragon", 60, 7, 12);
        Creature grog  = new Goblin("Grog the Sneaky", 40, 5, 0.3);

        BattleArena.fight(smaug, grog);
    }
}
```

## Finished Reference Code (from your project)

> These are the final versions of the code. Use them to compare with your progressive build above.

### Creature.java (final)


```java
package org.example;

public class Creature {
    String name;
    int health;
    int attackPower;

    public Creature(String name, int health, int attackPower) {
        this.name = name;
        this.health = health;
        this.attackPower = attackPower;
    }

    public void attack(Creature target) {
        System.out.println(this.name + " attacks " + target.name + ", dealing " + this.attackPower + " damage!");
        target.takeDamage(this.attackPower);
    }

    public void takeDamage(int damage) {
        this.health -= damage;
    }

    public boolean isAlive() {
        return this.health > 0;
    }

    public void display() {
        System.out.println("Name: " + name + ", Health: " + health + ", Attack: " + attackPower);
    }
}
```


### Dragon.java (final)


```java
package org.example;

import java.util.Random;

public class Dragon extends Creature {
    private int fireBreathPower;

    public Dragon(String name, int health, int attackPower, int fireBreathPower) {
        super(name, health, attackPower); // Calling the parent constructor
        this.fireBreathPower = fireBreathPower;
    }

    // Method Override
    @Override
    public void attack(Creature target) {
        // A 50% chance to breathe fire instead of a normal attack
        if (new Random().nextBoolean()) {
            System.out.println(this.name + " unleashes a torrent of fire!");
            breatheFire(target);
        } else {
            super.attack(target); // Calling the base class's attack method
        }
    }

    public void breatheFire(Creature target) {
        System.out.println(this.name + "'s fire breath deals " + this.fireBreathPower + " damage to " + target.name);
        target.takeDamage(this.fireBreathPower);
    }
}
```


### Goblin.java (final)


```java
package org.example;

public class Goblin extends Creature {
    private double dodgeChance;

    public Goblin(String name, int health, int attackPower, double dodgeChance) {
        super(name, health, attackPower);
        this.dodgeChance = dodgeChance;
    }

    // Method Override
    @Override
    public void takeDamage(int damage) {
        if (Math.random() < this.dodgeChance) {
            System.out.println(this.name + " dodged the attack!");
        } else {
            super.takeDamage(damage); // Let the parent class handle the damage
        }
    }
}
```


### BattleArena.java (final)


```java
package org.example;

public class BattleArena {
    public static void fight(Creature creature1, Creature creature2) {
        System.out.println("--- BATTLE START ---");
        creature1.display();
        creature2.display();
        System.out.println("--------------------");

        int round = 1;
        while (creature1.isAlive() && creature2.isAlive()) {
            System.out.println("\n--- Round " + round + " ---");

            // Creature 1 attacks Creature 2
            creature1.attack(creature2);
            if (!creature2.isAlive()) break; // Check if the fight is over

            // Creature 2 attacks Creature 1
            creature2.attack(creature1);

            // Display status at the end of the round
            creature1.display();
            creature2.display();
            round++;
        }

        System.out.println("\n--- BATTLE OVER ---");
        if (creature1.isAlive()) {
            System.out.println(creature1.name + " is the winner!");
        } else if (creature2.isAlive()) {
            System.out.println(creature2.name + " is the winner!");
        } else {
            System.out.println("It's a draw!");
        }
    }
}
```


### Main.java (final)


```java
package org.example;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        // Creating objects of the subclasses
        Creature smaug = new Dragon("Smaug the Golden", 100, 15, 30);
        Creature gribble = new Goblin("Gribble the Sneaky", 50, 8, 0.3);

        // Using the utility method to start the interaction
        BattleArena.fight(smaug, gribble);
    }
}
```