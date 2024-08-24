# Kirby Game

**Developed by: Ido Azulay & Maor Attar**
(Object-Oriented Programming Course 2: Final Project)

**Video Demo:** https://www.youtube.com/watch?v=W9YCN6WlRO8 
---

## About the Program

This game is a simplified version of "Kirby: Nightmare in Dream Land." The player controls Kirby, a pink, spherical character, in a vibrant world called Dream Land. Kirby's objective is to defeat various creatures and overcome his nightmare.

### Game Features

- **Stages**: The game includes three stages, each ending with a door leading to the next. To proceed, press the up arrow key to teleport Kirby to the next stage.
- **Controls**:
  - **Movement**: Use the right/left arrow keys to walk.
  - **Jump**: Press the X key.
  - **Fly**: Press the up arrow key.
  - **Bend Down**: Press the down arrow key.
  - **Inhale**: Press the Z key to inhale enemies.
- **Special Abilities**:
  - **Fire Kirby**: Inhale the fire enemy and press the down arrow key to gain the ability to breathe fire.
  - **Ice Kirby**: Inhale the ice enemy and press the down arrow key to gain the ability to breathe ice.
  - **Black Star Enemy**: This enemy cannot be defeated. Avoid engaging with it.
- **Additional Mechanics**:
  - **Shooting Stars**: Inhale regular enemies and press the X key to shoot stars.
  - **Exhaling Air**: While flying, press the Z key to exhale air and defeat enemies (note: no points are awarded for this).

### Scoring and Lives

- **Starting Lives**: The player begins with 5 lives.
- **Gifts**:
  - **Apples**: Collecting an apple adds 20 points to the score.
  - **Life Gifts**: Collecting a life gift grants an extra life.

---

## Data Structure

- **`std::vector<std::unique_ptr<MovingObject>> m_movingObjects`**: Vector to hold all moving objects in each stage.
- **`std::vector<std::unique_ptr<StaticObject>> m_staticObjects`**: Vector to hold all static objects in each stage.

  *(These vectors facilitate handling collisions between Kirby and map objects.)*

---

## Algorithm

- **Scale Factor**: The map's pixel dimensions are calculated relative to the sprite size, allowing the player to choose their preferred window size.
  ```cpp
  scaleFactor.x = min(window height / (board size x * SPRITE_SIZE), window width / (board size y * SPRITE_SIZE))
  scaleFactor.y = scaleFactor.x

## Design
**GameObject**: Base class inherited by StaticObject and MovingObject.
**StaticObject**: Base class for Apple and LifeGift.
**MovingObject**: Base class for Kirby, OrangeEnemy, IceManEnemy, FireEnemy, FlyingEnemy, PlantEnemy, BlackStarEnemy, SwordEnemy, AirPuff, InHale, KirbyStar.
**MapObject**: Base class for RightWall, LeftWall, Spike, Floor, Ceiling.
**Resources**: Resource manager class providing access to textures, sounds, and fonts. Implements the Singleton design pattern.
**Map**: Manages MovingObject and StaticObject vectors, and includes the Kirby class object, floor, walls, and other elements for map management.
**Controller**: Manages sf::Window, sf::Clock, Map, and Menu objects to control and run the game.
**Menu**: Manages the main menu (help, start, exit, back buttons) and the win/lose screens.
**Text and Fonts**: Handles loading of sprites, text, and fonts.


## Known Issues
**Animation Overlap**: When Kirby is hit by an enemy, the hitAnimation function is called. Sometimes, this animation overlaps with others.
**Special Powers Activation**: If Kirby inhales a special enemy and is facing left, Kirby cannot use the special power until he moves.

