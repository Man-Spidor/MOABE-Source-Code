#ifndef COLLIDABLEGROUP_H
#define COLLIDABLEGROUP_H

#include <list>

class Collidable;
class CollisionVolume;

/// Represents a group of collidable objects.
/// 
/// @note This class is for internal use only. 
class CollidableGroup
{
public:
    /// Collection of collidable objects.
    using CollidableCollection = std::list<Collidable*>;
    /// Default constructor.
    CollidableGroup();
    /// Copy constructor.
    CollidableGroup(const CollidableGroup& other) = default;
    /// Copy assignment operator.
    CollidableGroup& operator=(const CollidableGroup& other) = default;
    /// Move constructor.
    CollidableGroup(CollidableGroup&& other) = default;
    /// Move assignment operator.
    CollidableGroup& operator=(CollidableGroup&& other) = default;
    /// Destructor.
    ~CollidableGroup();

    /// Registers a collidable object with the group.
    ///
    /// @param pCol Pointer to the collidable object to register.
    void Register(Collidable* pCol);

    /// Deregisters a collidable object from the group.
    ///
    /// @param pCol Pointer to the collidable object to deregister.
    void Deregister(Collidable* pCol);

    /// Retrieves the collection of collidable objects.
    ///
    /// @return Reference to the collection of collidable objects.
    const CollidableCollection& GetColliderCollection() const;

    void UpdateGroupColData();

    const CollisionVolume& GetGroupColVol() const;

private:
    /// Collection of collidable objects.
    CollidableCollection collidableCollection;
    CollisionVolume* pGroupBox;
};


#endif // COLLIDABLEGROUP_H
