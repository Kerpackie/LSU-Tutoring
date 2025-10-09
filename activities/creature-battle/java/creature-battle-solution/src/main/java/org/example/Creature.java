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