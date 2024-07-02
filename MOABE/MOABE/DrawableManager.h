#ifndef DRAWABLEMANAGER_H
#define DRAWABLEMANAGER_H

#include <list>

class Drawable;

/// Manages all drawable objects in the game
/// 
/// @note This class is for internal use only.
class DrawableManager : public Align16
{
public:
    /// Default constructor
    DrawableManager() = default;
    /// Copy constructor deleted
    DrawableManager(const DrawableManager& other) = delete;
    /// Copy assignment operator deleted
    DrawableManager& operator=(const DrawableManager& other) = delete;
    /// Move constructor deleted
    DrawableManager(DrawableManager&& other) = delete;
    /// Move assignment operator deleted
    DrawableManager& operator=(DrawableManager&& other) = delete;
    /// Default destructor
    ~DrawableManager() = default;

    /// Clears The Registered Drawables and Resets Their Registration Status
    void ClearLists();

    /// Processes all drawable elements
    /// 
    /// Called once every frame.
    /// @see SceneManager
    void ProcessElements() const;

    /// Registers a drawable object with the manager
    /// @param dable The drawable object to register
    void Register3D(Drawable* dable);

    /// Deregisters a drawable object from the manager
    /// @param dable The drawable object to deregister
    void Deregister3D(Drawable* dable);

    /// Registers a drawable object with the manager
    /// @param dable The drawable object to register
    void Register2D(Drawable* dable);

    /// Deregisters a drawable object from the manager
    /// @param dable The drawable object to deregister
    void Deregister2D(Drawable* dable);

private:
    using DrawableList = std::list<Drawable*>;
    DrawableList DrawList3D; ///< The list of 3D drawable objects
    DrawableList DrawList2D; ///< The list of 2D drawable objects

public:
    ///< Iterator type for the list of drawables
    /// Used by Drawables to track their place in the DrawableList for quick deletion.
    /// @see Drawable::myDeleteRef
    using DrawableListRef = DrawableList::iterator; 
};

#endif // DRAWABLEMANAGER_H
