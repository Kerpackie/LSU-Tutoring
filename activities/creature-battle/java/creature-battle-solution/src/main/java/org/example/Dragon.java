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