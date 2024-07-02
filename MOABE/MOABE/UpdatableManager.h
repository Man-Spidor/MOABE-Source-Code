#ifndef UPDATABLEMANAGER_H
#define UPDATABLEMANAGER_H

#include <list>

class Updatable;

/// Manages all updatable objects in the game
class UpdatableManager : public Align16
{
public:
    /// Default constructor
    UpdatableManager() = default;
    /// Copy constructor deleted
    UpdatableManager(const UpdatableManager& other) = delete;
    /// Copy assignment operator deleted
    UpdatableManager& operator=(const UpdatableManager& other) = delete;
    /// Move constructor deleted
    UpdatableManager(UpdatableManager&& other) = delete;
    /// Move assignment operator deleted
    UpdatableManager& operator=(UpdatableManager&& other) = delete;
    /// Default destructor
    ~UpdatableManager() = default;

    /// Clears The Registered Updatables and Resets Their Registration Status
    void ClearLists();

    /// Processes all updatable elements
    /// 
    /// Called once every frame.
    void ProcessElements() const;

    /// Registers an updatable object with the manager
    /// @param upable The updatable object to register
    void Register(Updatable* upable);

    /// Deregisters an updatable object from the manager
    /// @param upable The updatable object to deregister
    void Deregister(Updatable* upable);

private:
    using UpdatableList = std::list<Updatable*>;
    UpdatableList updateList; ///< The list of updatable objects
public:
    ///< Iterator type for the list of updatables
    /// Used by Updatables to track their place in the UpdatableList for quick deletion.
    /// @see Updatable::myDeleteRef
    using UpdatableListRef = UpdatableList::iterator; 
};

#endif // UPDATABLEMANAGER_H
