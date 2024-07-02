#ifndef COLLIDABLEMANAGER_H
#define COLLIDABLEMANAGER_H

#include "CollisionDispatch.h"
#include "CollisionTerrainDispatch.h"
#include "CollisionTestSelfCmd.h"
#include "CollisionTestPairCmd.h"
#include "CollisionTestTerrainCmd.h"

#include <vector>
#include <list>

class CollidableGroup;
class CollisionTestCommand;

/// Manages collisions between collidable objects.
///
/// @note This class is for internal use only. 
class CollisionManager : public Align16
{
public:
    /// The type ID used to identify collision groups.
    using ColID = unsigned int;

    /// Value representing an undefined collision ID.
    static const ColID COLID_UNDEFINED = UINT_MAX;

private:
    static ColID TypeIDNextNumber;

public:
    /// Default constructor.
    CollisionManager();
    /// Copy constructor.
    CollisionManager(const CollisionManager& other) = delete;
    /// Copy assignment operator.
    CollisionManager& operator=(const CollisionManager& other) = delete;
    /// Move constructor.
    CollisionManager(CollisionManager&& other) = delete;
    /// Move assignment operator.
    CollisionManager& operator=(CollisionManager&& other) = delete;
    /// Destructor.
    virtual ~CollisionManager();

    /// Processes collisions between collidable objects.
    void ProcessCollisions();

    /// Resets the collision ID.
    void ResetCollisionID();

    /// Registers a collidable object with the collision manager.
    ///
    /// @param pCol Pointer to the collidable object to register.
    void Register(Collidable* pCol);

    /// Deregisters a collidable object from the collision manager.
    ///
    /// @param pCol Pointer to the collidable object to deregister.
    void Deregister(Collidable* pCol);

    /// Initializes the collision group collection.
    ///
    /// This function is called once by the SceneManager when initializing the first scene.
    void InitializeColGroupCollection();

    /// Retrieves the collision group associated with the specified ID.
    ///
    /// @param id The ID of the collision group to retrieve.
    /// @return Pointer to the collision group if found, throws error otherwise.
    CollidableGroup* GetCollisionGroup(const ColID id) const;

private:
    /// Collection of collision groups.
    using CollidableGroupCollection = std::vector<CollidableGroup*>;
    static CollidableGroupCollection ColGroupCollection;

    /// List of collision test commands.
    using CollisionTestCommands = std::list<CollisionTestCommand*>;
    CollisionTestCommands colTestCommands;

    /// Sets the group for the specified type ID.
    ///
    /// @param ind The type ID index.
    void SetGroupForTypeID(const ColID ind);

public:
    /// Generates a unique type ID for the specified collidable type.
    ///
    /// @tparam C The collidable type.
    /// @return The generated type ID.
    template <typename C>
    ColID GetID()
    {
        static ColID myTypeID = TypeIDNextNumber++;

        SetGroupForTypeID(myTypeID);

        Trace::out("Type ID: %i\n", myTypeID);
        return myTypeID;
    }

    /// Sets up collision detection for a collidable type with itself.
    ///
    /// @tparam C The collidable type.
    template< typename C>
    void SetCollisionSelf()
    {
        CollidableGroup* pColGroup = this->ColGroupCollection[this->GetID<C>()];

        CollisionDispatchProxy* pDispatch = new CollisionDispatch<C, C>();

        colTestCommands.push_back(new CollisionTestSelfCmd(pDispatch, *pColGroup));
    }

    /// Sets up collision detection between two collidable types.
    ///
    /// @tparam C1 The first collidable type.
    /// @tparam C2 The second collidable type.
    template< typename C1, typename C2>
    void SetCollisionPair()
    {
        CollidableGroup* pColGroup1 = this->ColGroupCollection[this->GetID<C1>()];
        CollidableGroup* pColGroup2 = this->ColGroupCollection[this->GetID<C2>()];

        CollisionDispatchProxy* pDispatch = new CollisionDispatch<C1, C2>();

        colTestCommands.push_back(new CollisionTestPairCmd(pDispatch, *pColGroup1, *pColGroup2));
    }

    template<typename C>
    void SetCollisionTerrain()
    {
        CollidableGroup* pColGroup = this->ColGroupCollection[this->GetID<C>()];

        CollisionDispatchProxy* pDispatch = new CollisionTerrainDispatch<C>();

        colTestCommands.push_back(new CollisionTestTerrainCmd(pDispatch, *pColGroup));
    }
};

#endif // COLLIDABLEMANAGER_H
