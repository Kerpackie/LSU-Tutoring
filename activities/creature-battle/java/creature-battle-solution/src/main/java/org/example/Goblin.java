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