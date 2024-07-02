#include "CollisionTestPairCmd.h"

#include "CollisionDispatch.h"

#include "GameObjectAttorney.h"
#include <VolumeAttorney.h>

#include "Colors.h"
#include "Visualizer.h"
#include "EngineMath.h"

CollisionTestPairCmd::~CollisionTestPairCmd()
{
    delete this->pDispatch;
}

CollisionTestPairCmd::CollisionTestPairCmd(CollisionDispatchProxy* _pDispatch, CollidableGroup& _colGroup1, CollidableGroup& _colGroup2) :
    pDispatch(_pDispatch),
    colGroup1(_colGroup1),
    colGroup2(_colGroup2)
{
}

void CollisionTestPairCmd::Execute() const
{
    // Get the Collidable Groups
    const CollidableGroup::CollidableCollection& Collection1 = colGroup1.GetColliderCollection();
    const CollidableGroup::CollidableCollection& Collection2 = colGroup2.GetColliderCollection();

    // ----------------------------------------------------------------------------------------
    // Early Out If There Are No Collidables To Test
    // ----------------------------------------------------------------------------------------
    if (Collection1.empty() || Collection2.empty())
        return;

    const CollisionVolume& CollectionVolume1 = this->colGroup1.GetGroupColVol();
    const CollisionVolume& CollectionVolume2 = this->colGroup2.GetGroupColVol();

    // ----------------------------------------------------------------------------------------
    // Test The Group Volumes Against One Another
    // ----------------------------------------------------------------------------------------

    if (!EngineMath::Intersect(CollectionVolume1, CollectionVolume2)) {
        Visualizer::SetLowestTestVolume(this->colGroup1.GetColliderCollection().front(), &CollectionVolume1);
        Visualizer::SetLowestTestVolume(this->colGroup2.GetColliderCollection().front(), &CollectionVolume2);
        return;
    }

    for (auto it1 = Collection1.begin(); it1 != Collection1.end(); it1++) {
        const CollisionVolume& pPrimVol1 = GameObjectAttorney::Collision::GetColPrimitiveVolume(*it1);

        // ----------------------------------------------------------------------------------------
        // Test Collidable1's primitive volume against CollidableGroup2's group volume
        // ----------------------------------------------------------------------------------------
        if (EngineMath::Intersect(CollectionVolume2, pPrimVol1)) {
            const CollisionVolume& pColVol1 = GameObjectAttorney::Collision::GetColVol(*it1);

            for (auto it2 = Collection2.begin(); it2 != Collection2.end(); it2++) {
                const CollisionVolume& pPrimVol2 = GameObjectAttorney::Collision::GetColPrimitiveVolume(*it2);

                // --------------------------------------------------------------------------------
                // Test Collidable2's primitive volume against CollidableGroup1's group volume
                // --------------------------------------------------------------------------------
                if (EngineMath::Intersect(CollectionVolume1, pPrimVol2)) {
                    // --------------------------------------------------------------------------------
                    // Test Collidable1's primitive volume against Collidable2's primitive volume
                    // --------------------------------------------------------------------------------
                    if (EngineMath::Intersect(pPrimVol1, pPrimVol2)) {
                        const CollisionVolume& pColVol2 = GameObjectAttorney::Collision::GetColVol(*it2);

                        // ----------------------------------------------------------------------------------------
                        // Test The Actual Collision Volumes
                        // ----------------------------------------------------------------------------------------
                        if (EngineMath::Intersect(pColVol1, pColVol2)) {
                            Visualizer::SetLowestTestVolume(*it1, &pColVol1, Colors::Red);
                            Visualizer::SetLowestTestVolume(*it2, &pColVol2, Colors::Red);
                            pDispatch->ProcessCallbacks(*it1, *it2);
                        }
                        else {
                            Visualizer::SetLowestTestVolume(*it1, &pColVol1);
                            Visualizer::SetLowestTestVolume(*it2, &pColVol2);
                        }
                    }
                    else {
                        Visualizer::SetLowestTestVolume(*it1, ((CollisionVolume*)&pPrimVol1));
                        Visualizer::SetLowestTestVolume(*it2, ((CollisionVolume*)&pPrimVol2));
                    }
                }
                else {
                    Visualizer::SetLowestTestVolume(*it2, ((CollisionVolume*)&pPrimVol2));
                    Visualizer::ShowVolume(CollectionVolume1);
                }
            }
        }
        else {
            Visualizer::SetLowestTestVolume(*it1, &pPrimVol1);
            Visualizer::ShowVolume(CollectionVolume2);
        }
    }
}
