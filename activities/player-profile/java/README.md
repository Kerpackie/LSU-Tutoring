# Exercise: Building a Secure Player Profile (Java Version)

In this activity, you will create a **PlayerProfile** class for a video game. The main goal is to protect the player's data using **encapsulation**, ensuring that it can only be accessed and modified in controlled ways.

---

## Step 1: Encapsulate the Player's Data

First, we need to define the `PlayerProfile` class and make its data private. This is the core of encapsulation—bundling data and the methods that operate on that data together, while hiding the data from the outside world.

### Instructions

Create a Java class named `PlayerProfile`. It should have the following private fields (instance variables):

* `username` (String)
* `email` (String)
* `level` (int)
* `experiencePoints` (int)
* `playerId` (UUID) — A universally unique identifier.

  > You’ll need to import `java.util.UUID;` for this.

---

## Step 2: Create Constructors

Constructors are special methods for creating and initializing objects. A class can have multiple constructors (overloading) to provide different ways of creating an object.

### Instructions

Add the following three constructors to your `PlayerProfile` class:

#### No-Args Constructor

* A **public constructor** that takes no arguments.
* Initialize:

  * `username` to `"NewPlayer"`
  * `level` to `1`
  * `experiencePoints` to `0`
  * `playerId` using `UUID.randomUUID()`
* Leave `email` as `null` or an empty string.

#### Some-Args Constructor

* A **public constructor** that accepts a `username` and `email`.
* Set the provided `username` and `email`.
* Initialize:

  * `level` to `1`
  * `experiencePoints` to `0`
  * `playerId` using `UUID.randomUUID()`

#### All-Args Constructor

* A **public constructor** that accepts `username`, `email`, `level`, and `experiencePoints`.
* Useful for loading existing player data.
* Set all fields and generate a new `playerId`.

---

## Step 3: Provide Controlled Access with Getters and Setters

We need a way to read and modify our private fields from outside the class, but in a **controlled manner**. In Java, we use public getter and setter methods for this.

### Rules

#### PlayerId (Read-Only)

* Create a getter `getPlayerId()` that returns the `playerId`.
* Do **not** create a setter.
* Make `playerId` **final** so it cannot be changed.

#### Username (Read/Write with Validation)

* `getUsername()` returns the username.
* `setUsername(String username)` validates input:

  * Must not be null.
  * Must be at least 3 characters long.
  * If invalid, print an error message and do not change the value.

#### Email (Read/Write)

* Standard getter and setter.

#### Level (Read-Only)

* `getLevel()` — no setter.

#### ExperiencePoints (Read-Only)

* `getExperiencePoints()` — no setter.

---

## Step 4: Add a Public Method for Business Logic

Create:

```java
public void gainExperience(int points)
```

This should:

* Add points to `experiencePoints`.
* If total `experiencePoints` >= 1000:

  * Increment `level`
  * Subtract or reset experience points.
* Print a message when the player levels up.

---

## Step 5: Override `toString()` for Easy Display

Override `toString()` to make object output readable:

```java
@Override
public String toString() {
    return "[Player: " + username + ", Level: " + level + "]";
}
```

**Example Output:**

```
[Player: TheLegend27, Level: 5]
```

---

## Step 6: Put It All Together

Create a `Main` class with `public static void main(String[] args)` to test your `PlayerProfile`.

### Example:

```java
public class Main {
    public static void main(String[] args) {
        PlayerProfile player = new PlayerProfile("TheLegend27", "legend@example.com");

        player.setUsername("Hero123"); // valid
        player.setUsername("ab");      // invalid

        player.gainExperience(1200);
        player.gainExperience(800);
        player.gainExperience(2000);

        System.out.println(player);
    }
}
```

---

### Expected Output:

```
Error: Username must be at least 3 characters long.
Level up! You are now level 2!
Level up! You are now level 3!
Level up! You are now level 4!
[Player: Hero123, Level: 4]
```
