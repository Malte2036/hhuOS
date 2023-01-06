# Docs: GameEngine

This documentation, is intended to document the public interfaces for the end user
and not the internal interfaces of the game engine.

## Engine:

### `Engine(Game *game, LinearFrameBuffer *lfb, uint8_t targetFrameRate = 60)`

- `Game *game`
- `Util::Graphic::LinearFrameBuffer *lfb`
- `uint8_t targetFrameRate`

## Game:

### `Game()`

- `drawInitialBackground(Util::Game::Graphics2D &graphics) override`: draw the statically drawn background
- `void update(double delta) override`: this function is called every frame
- `void keyPressed(char c) override`: this function is called, when the user presses an key
- `void addEntity(Entity *entity)`: add entity
- `void removeEntity(Entity *entity)`: remove entity
- `void stop()`: stop the game
- `Camera *getCamera()`: the current camera of the game *[also see 🔗 [Camera](#camera)]*

## Camera:

`Camera(Vector2 position)`
- `Vector2 getPosition()`
- `void setPosition(Vector2 position)`: changes the camera position
_[hint: Set the Camera Position to the Position of your Player Entity ([Entity/Event/TranslateEvent](#translateeventvector2-translateto)), to let the Camera follow your player.]_


## GameManager

### `static GameManager`

- `static setGame<GameType>(GameType *value)`: sets the current game, to access it later
  - with `GameType` type of your Game *[also see 🔗 [Game](#game)]*
- `static GameType *getGame<GameType>()`
  - with `GameType` type of your Game *[also see 🔗 [Game](#game)]*
- `static Vector2 getResolution()`: screen resolution

## Entity:

### `Entity(String tag, Vector2 position, RectangleCollider *collider = nullptr)`:

- `String tag`: Freely selectable name or type of an entity. For later identification of the entity.
- `Vector2 position`: position of the entity
- `RectangleCollider *collider`: collider of the entity (can be omitted)
- `String getTag()`
- `Vector2 getPosition()`
- `RectangleCollider *getCollider()`
- `void setPosition(Vector2 vector2)`: set the position of the entity
- `void translate(Vector2 vector2)`: move the entity relatively in the direction of the vector
- `void translateX(double x)`: move the entity by `x` in x-direction
- `void translateY(double y)`
- `virtual void onUpdate(double dt)`: this function is called every frame
- `virtual void onTranslateEvent(TranslateEvent *event)`: every time `translate(...)`, `translateX(...)` or `translateY(...)` is called, this function is automatically triggered. If the event is canceled (`event→setCanceled(true)`), the entity will not be translated. *[also see 🔗 [Entity/Event/TranslateEvent](#translateeventvector2-translateto)]*
- `virtual void onCollisionEvent(CollisionEvent *event)`: is called when the collider of this entity overlaps with another collider. *[also see 🔗 [Entity/Event/CollisionEvent](#collisionevententity-other-rectanglecollidedside-rectanglecollidedside)]*
- `void addComponent(Component *component)`: call this function, to add Components to this Entity. For example the GravityComponent. *[also see 🔗 [Entity/Component/GravityComponent](#gravitycomponentdouble-groundy)]*

### Component:

#### `Component()`:

- `String getType()`: returns the component type
- `Entity* getEntity()`: returns the entity

#### `LinearMovementComponent()`:

- *extends `Component`*
  - with `type = "LinearMovementComponent"`

#### `GravityComponent(double groundY)`:

- *extends `Component`*
  - with `type = "GravityComponent"`
- `double groundY`: the y coordinate of the ground
- `double mass = 1`
- `double stopFactorX = 0.9`: movement stop factor
- `double gravityValue = -1`

### Event:

#### `Event()`:

- `String getType()`: returns the event type

#### `CancelableEvent()`:

- *extends `Event`*
- `bool isCanceled()`
- `void setCanceled(bool value)`: sets the event to canceled

#### `TranslateEvent(Vector2 translateTo)`:

- *extends `CancelableEvent`*
  - with `type = "TranslateEvent"`
- `Vector2 translateTo`: Vector to move to
- `Vector2 getTranslateTo()`

#### `CollisionEvent(Entity *other, RectangleCollidedSide rectangleCollidedSide)`:

- *extends `Event`*
  - with `type = "CollisionEvent"`
- `Entity *entity`: entity that was collided with.
- `RectangleCollidedSide rectangleCollidedSide`: the side that collided
(`LEFT_SIDE`, `RIGHT_SIDE`, `TOP_SIDE`, `BOTTOM_SIDE`, `NO_SIDE`)
- `Entity *getCollidedWith()`
-  `RectangleCollidedSide getRectangleCollidedSide()`

### Collider:

#### `Collider(String type, Vector2 position, ColliderType colliderType)`:

- `String type`: type of the Collider
- `Vector2 position`
- `ColliderType colliderType`: whether this is an `STATIC_COLLIDER` or `DYNAMIC_COLLIDER`
- `String getType()`: returns the collider type
- `Vector2 getPosition()`
- `ColliderType getColliderType()`

#### `RectangleCollider(Vector2 position, double height, double width, ColliderType colliderType)`:

- *extends* `Collider`
  - with `type = “RectangleCollider”`
- `Vector2 position`
- `double height`
- `double width`
- `ColliderType colliderType`
- `void setHeight(double val)`
- `void setWidth(double val)`

## UI:

### `GameText(Vector2 position, String text, Color color)`

- `Vector2 position`
- `String text`: text do be drawn
- `Color color`: text color (can be omitted)
- `void setText(String value)`: change drawn text

## Math:

### `Vector2(double x, double y)`:

- `double x`: x-position
- `double y`: y-position
- `Vector2 &operator*(double value)`
- `Vector2 &operator+(const Vector2 &other)`
- `Vector2 &operator-(const Vector2 &other);`
- `Vector2 normalize()`
- `double length()`
- `double getX()`
- `double getY()`
