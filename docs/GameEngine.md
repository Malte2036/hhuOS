# Docs: GameEngine

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
- `void onTranslateEvent(TranslateEvent *event)`: every time `translate(...)`, `translateX(...)` or `translateY(...)` is called, this function is automatically triggered. If the event is canceled (`event→setCanceled(true)`), the entity will not be translated. *[also see 🔗 Events/TranslateEvent]*
- `void onCollisionEvent(CollisionEvent *event)`: is called when the collider of this entity overlaps with another collider. *[also see 🔗 Events/CollisionEvent]*

### `GravityEntity(String tag, Vector2 position)`:

- *extends `Entity`*
- same properties as `Entity`, except that `GravityEntity` moves “smoother” and follows the laws of gravity.

## Events:

### `Event()`:

- `String getType()`: returns the event type

### `CancelableEvent()`:

- *extends `Event`*
- `bool isCanceled()`
- `void setCanceled(bool value)`: sets the event to canceled

### `TranslateEvent(Vector2 translateTo)`:

- *extends `CancelableEvent`*
  - `type = "TranslateEvent"`
- `Vector2 translateTo`: Vector to move to.
- `Vector2 getTranslateTo()`

### `CollisionEvent(Entity *other)`:

- *extends `Event`*
  - with `type = "CollisionEvent"`
- `Entity *entity`: entity that was collided with.
- `Entity *getCollidedWith()`

## Collider:

### `Collider(String type, Vector2 position)`:

- …

### `RectangleCollider(Vector2 position, double height, double width)`:

- *extends* `Collider`
  - with `type = “RectangleCollider”`
- …

## UI:

### `GameText(Vector2 position, String text, Color color)`

- `Vector3 position`
- `String text`: text do be drawn
- `Color color`: text color (can be omitted)
- `void setText(String value)`: change drawn text

## Math:

### `Vector2(double x, double y)`:

- `double x`: x-position
- `double y`: y-position