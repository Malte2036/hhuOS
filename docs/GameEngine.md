# Docs: GameEngine

This documentation, is intended to document the public interfaces for the end user
and not the internal interfaces of the game engine.

## Engine:

### `Engine(Game &game, const Util::Graphic::LinearFrameBuffer &lfb, const uint8_t targetFrameRate)`

- `Game *game`
- `Util::Graphic::LinearFrameBuffer *lfb`
- `uint8_t targetFrameRate`
- `void setBackgroundColor(Color backgroundColor)`

## Game:

- `void update(double delta)`
- `Camera *getCamera()`: the current camera of the game *[also see 🔗 [Camera](#camera)]*

## Camera:
`Camera(Vector2 position)`
- `Vector2 getPosition()`
- `void setPosition(Vector2 position)`: changes the camera position
_[hint: Set the Camera Position to the Position of your Player Entity ([Entity/Event/TranslateEvent](#translateeventvector2-translateto)), to let the Camera follow your player.]_


## GameManager

### `static GameManager<typename GameType>`

  - with `GameType` type of your Game *[also see 🔗 [Game](#game)]*
- `static setGame(GameType *value)`: sets the current game, to access it later
- `static GameType *getGame()`

## Entity:

### `Entity(String tag, Vector2 position)`:

- `String tag`: Freely selectable name or type of an entity. For later identification of the entity.
- `Vector2 position`: current position of the entity
- `String getTag()`
- `Vector2 getPosition()`
- `void setPosition(Vector2 vector2)`: set the position of the entity
- `void translate(Vector2 vector2)`: move the entity relatively in the direction of the vector
- `void translateX(double x)`: move the entity by `x` in x-direction
- `void translateY(double y)`
- `void onTranslateEvent(TranslateEvent *event)`: every time `translate(...)`, `translateX(...)` or `translateY(...)` is called, this function is automatically triggered. If the event is canceled (`event→setCanceled(true)`), the entity will not be translated. *[also see 🔗 [Entity/Event/TranslateEvent](#translateeventvector2-translateto)]*
- `void onCollisionEvent(CollisionEvent *event)`: is called when the collider of this entity overlaps with another collider. *[also see 🔗 [Entity/Event/CollisionEvent](#collisionevententity-other)]*
- `void addComponent(Component *component)`: call this function, to add Components to this Entity. For example the GravityComponent. *[also see 🔗 [Entity/Component/GravityComponent](#gravitycomponent)]*

### Component:

#### `Component()`:

- `String getType()`: returns the component type
- `Entity* getEntity()`: returns the entity

#### `LinearMovementComponent()`:

- *extends `Component`*
  - with `type = "LinearMovementComponent"`

#### `GravityComponent()`:

- *extends `Component`*
  - with `type = "GravityComponent"`

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
- `Vector2 translateTo`: Vector to move to.
- `Vector2 getTranslateTo()`

#### `CollisionEvent(Entity *other)`:

- *extends `Event`*
  - with `type = "CollisionEvent"`
- `Entity *entity`: entity that was collided with.
- `Entity *getCollidedWith()`

### Collider:

#### `Collider(String type, Vector2 position)`:

- …

#### `RectangleCollider(Vector2 position, double height, double width)`:

- *extends* `Collider`
  - with `type = “RectangleCollider”`
- …

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