#include "EngineMath.h"

#include "CV_OBB.h"
#include "CV_AABB.h"
#include "CV_BSphere.h"

#include "MOABESpotLight.h"
#include "MOABEPointLight.h"

#include "VolumeAttorney.h"

#include <TerrainModel.h>
#include <Visualizer.h>
#include <Colors.h>

const Vect EngineMath::ClampPoint(const Vect& point, const Vect& min, const Vect& max)
{
    Vect retVect = point;

    if (retVect.X() < min.X())
        retVect.X() = min.X();

    else if (retVect.X() > max.X())
        retVect.X() = max.X();

    if (retVect.Y() < min.Y())
        retVect.Y() = min.Y();

    else if (retVect.Y() > max.Y())
        retVect.Y() = max.Y();

    if (retVect.Z() < min.Z())
        retVect.Z() = min.Z();

    else if (retVect.Z() > max.Z())
        retVect.Z() = max.Z();

    return retVect;
}

bool EngineMath::IntervalOverlap(const Vect& A, const Vect& B, const Vect& C, const Vect& D)
{
    return      EngineMath::IntervalOverlap(A.X(), B.X(), C.X(), D.X())
        && EngineMath::IntervalOverlap(A.Y(), B.Y(), C.Y(), D.Y())
        && EngineMath::IntervalOverlap(A.Z(), B.Z(), C.Z(), D.Z());
}

bool EngineMath::IntervalOverlap(const float a, const float b, const float c, const float d)
{
    return (b > c) && (d > a);
}

// Vect localAxis = Axis * Box.GetWorldInv();   
// float result = abs(Box.GetDiag().dot(localAxis)) / axisMag;
// result *= Box.GetScaleSqr();
// return result; 
const float EngineMath::MaxHalfProjection(const CV_BoxBase& Box, const Vect& Axis, const float AxisMag)
{
    return Box.GetScaleSqr() * ((abs(Box.GetDiag().X() * Axis.X()) + abs(Box.GetDiag().Y() * Axis.Y()) + abs(Box.GetDiag().Z() * Axis.Z())) / AxisMag);
}

const float EngineMath::MaxHalfProjection(const TerrainCell& Cell, const Vect& Axis, const float AxisMag)
{
    return std::powf(*Cell.CellWidth, 2.0f) * ((abs(Cell.HalfDiagonal.X() * Axis.X()) + abs(Cell.HalfDiagonal.Y() * Axis.Y()) + abs(Cell.HalfDiagonal.Z() * Axis.Z())) / AxisMag);
}

// bool result = true;
// if (axisMag > FLT_EPSILON) {
//     float proj1 = EngineMath::MaxHalfProjection(A, axis * A.GetWorldInv(), axisMag);
//     float proj2 = EngineMath::MaxHalfProjection(B, axis * B.GetWorldInv(), axisMag);
// 
//     result = EngineMath::AxisOverlap(A.GetCenter(), B.GetCenter(), axis, proj1, proj2, axisMag);
// }
// 
// return result;
const bool EngineMath::TestAxis(const CV_BoxBase& A, const CV_BoxBase& B, const Vect& axis, const float axisMag)
{
    if (axisMag <= FLT_EPSILON)
        return true;

    return EngineMath::AxisOverlap(A.GetCenter(), B.GetCenter(), axis, EngineMath::MaxHalfProjection(A, axis * A.GetWorldInv(), axisMag), EngineMath::MaxHalfProjection(B, axis * B.GetWorldInv(), axisMag), axisMag);
}

const bool EngineMath::TestAxis(const CV_BoxBase& A, const TerrainCell& B, const Matrix& CellWorldInv, const Vect& axis, const float axisMag)
{
    bool result = true;
    if (axisMag > FLT_EPSILON) {
        float proj1 = EngineMath::MaxHalfProjection(A, axis * A.GetWorldInv(), axisMag);
        float proj2 = EngineMath::MaxHalfProjection(B, axis * CellWorldInv, axisMag);

        result = EngineMath::AxisOverlap(A.GetCenter(), B.Center, axis, proj1, proj2, axisMag);
    }

    return result;
}

const bool EngineMath::AxisOverlap(const Vect& Center1, const Vect& Center2, const Vect& Axis, const float proj1, const float proj2, const float AxisMag)
{
    return  abs(Axis.dot(Center2 - Center1)) / AxisMag <= proj1 + proj2;
}

/// Vect clampedCenter = EngineMath::ClampPoint(Point, Min, Max);
/// 
/// Vect distToClamped = clampedCenter - Point;
/// 
/// bool result = distToClamped.magSqr() < TestDist;
/// return result;
const bool EngineMath::TestPointMinMax(const Vect& Point, const Vect& Min, const Vect& Max, const float TestDist)
{
     Vect clampedCenter = EngineMath::ClampPoint(Point, Min, Max);
     
     Vect distToClamped = clampedCenter - Point;
     
     bool result = distToClamped.magSqr() < TestDist;
     return result;
}

/// Vect clampedCenter = EngineMath::ClampPoint(Point * WorldInv, Min, Max);
/// 
/// Vect clampedWorldCenter = clampedCenter * World;
/// 
/// bool result = (clampedWorldCenter - Point).magSqr() < TestDist;
/// 
/// return result;
const bool EngineMath::TestPointMinMaxWorldToLocal(const Matrix& World, const Matrix& WorldInv, const Vect& Point, const Vect& Min, const Vect& Max, const float TestDist)
{
    return (EngineMath::ClampPoint(Point * WorldInv, Min, Max) * World - Point).magSqr() < TestDist;
}

const bool EngineMath::TestPointTerrainCell(const TerrainCell& Cell, const Vect& Point, const float TestDist)
{
    return EngineMath::TestPointMinMax(Point, Cell.Min, Cell.Max, TestDist);
}

const bool EngineMath::TestPointTerrainCellByPos(const TerrainModel& Terrain, const float cellwidth, const float x, const float z, const Vect& Point, const float TestDist)
{
    return EngineMath::TestPointTerrainCell(EngineMath::GetTerrainCellByPosition(Terrain, cellwidth, x, z), Point, TestDist);
}

const bool EngineMath::Intersect(const CollisionVolume& A, const CollisionVolume& B)
{
    return VolumeAttorney::IntersectAccept(A, B);
}

const bool EngineMath::Intersect(const CV_BSphere& A, const CV_BSphere& B)
{
    // Calculate the distance between the centers of the two spheres
    float distanceSquared = (A.GetCenter() - B.GetCenter()).magSqr();

    // Calculate the sum of the radii squared
    float sumRadiiSquared = (A.GetRadius() * A.GetRadius()) + (B.GetRadius() * B.GetRadius());

    // Check if the distance between the centers is less than the sum of the radii
    return distanceSquared <= sumRadiiSquared;
}

const bool EngineMath::Intersect(const CV_AABB& A, const CV_AABB& B)
{
    return EngineMath::IntervalOverlap(A.GetMin(), A.GetMax(), B.GetMin(), B.GetMax());
}

const bool EngineMath::Intersect(const CV_AABB& A, const CV_BSphere& B)
{
    return EngineMath::TestPointMinMax(B.GetCenter(), A.GetMin(), A.GetMax(), B.GetRadiusSqr());
}

const bool EngineMath::Intersect(const CV_OBB& A, const CV_BSphere& B)
{
    return EngineMath::TestPointMinMaxWorldToLocal(A.GetWorld(), A.GetWorldInv(), B.GetCenter(), A.GetMin(), A.GetMax(), B.GetRadiusSqr());
}

const bool EngineMath::Intersect(const CV_OBB& A, const CV_OBB& B)
{
    bool result = true;

    const Matrix& AWorld = A.GetWorld();
    const Matrix& BWorld = B.GetWorld();
    
    int i = 0, j = 0;
    while (result && i < 3) {
        const Vect& AVect = AWorld.get(MatrixRowType(i));
        result = EngineMath::TestAxis(A, B, AVect, AVect.mag());

        if (result) {
            result = EngineMath::TestAxis(A, B, BWorld.get(MatrixRowType(i)), BWorld.get(MatrixRowType(i)).mag());
        }
        j = 0;
        while (result && j < 3) {
            const Vect& BVect = BWorld.get(MatrixRowType(j));

            const Vect& axis = AVect.cross(BVect);
            result = EngineMath::TestAxis(A, B, axis, axis.mag());

            j++;
        }
        i++;
    }

    return result;
}

const bool EngineMath::Intersect(const CV_OBB& A, const CV_AABB& B)
{
    bool result = true;

    const Matrix& AWorld = A.GetWorld();

    int i = 0;
    while (result && i < 3) {
        const Vect& AVect = AWorld.get(MatrixRowType(i));
        result = EngineMath::TestAxis(A, B, AVect, AVect.mag());
        if (!result)
            break;

        result = EngineMath::TestAxis(A, B, B.GetWorld().get(MatrixRowType(i)), B.GetWorld().get(MatrixRowType(i)).mag());
        if (!result)
            break;

        // Test the cross products of the axes
        // Since the Axes of the AABB are always the world axes, we can hard code this
        const Vect axisX = AVect.cross(B.GetWorld().get(ROW_0));
        result = EngineMath::TestAxis(A, B, axisX, axisX.mag());
        if (!result)
            break;

        const Vect axisY = AVect.cross(B.GetWorld().get(ROW_1));
        result = EngineMath::TestAxis(A, B, axisY, axisY.mag());

        if (!result)
            break;

        const Vect axisZ = AVect.cross(B.GetWorld().get(ROW_2));
        result = EngineMath::TestAxis(A, B, axisZ, axisZ.mag());

        if (!result)
            break;
        i++;
    }

    return result;
}

const bool EngineMath::Intersect(const TerrainCell& Cell, const CV_BSphere& BSphere)
{
    return EngineMath::TestPointTerrainCell(Cell, BSphere.GetCenter(), BSphere.GetRadiusSqr());
}

const bool EngineMath::Intersect(const TerrainCell& Cell, const CV_OBB& OBB)
{    
    const Matrix CellWorldInv = Matrix(*Cell.XAxis, Cell.YAxis, *Cell.ZAxis, Cell.Center).getInv();

    if (!EngineMath::TestAxis(OBB, Cell, CellWorldInv, *Cell.XAxis, *Cell.CellWidth))
        return false;

    if (!EngineMath::TestAxis(OBB, Cell, CellWorldInv, *Cell.ZAxis, *Cell.CellWidth))
        return false;
    
    if (!EngineMath::TestAxis(OBB, Cell, CellWorldInv, Cell.YAxis, Cell.YMag))
        return false;

    const Matrix& OBBWorld = OBB.GetWorld();

    bool result = true;
    
    int i = 0;
    while (result && i < 3) {
        const Vect& AVect = OBBWorld.get(MatrixRowType(i));
        result = EngineMath::TestAxis(OBB, Cell, CellWorldInv, AVect, AVect.mag());
        if (!result)
            break;
        
        // Test the cross products of the axes
        const Vect axisX = Cell.XAxis->cross(AVect);
        result = EngineMath::TestAxis(OBB, Cell, CellWorldInv, axisX, axisX.mag());
        if (!result) 
            break;

        const Vect axisY = Cell.ZAxis->cross(AVect);
        result = EngineMath::TestAxis(OBB, Cell, CellWorldInv, axisY, axisY.mag());

        if (!result)
            break;

        const Vect axisZ = Cell.YAxis.cross(AVect);
        result = EngineMath::TestAxis(OBB, Cell, CellWorldInv, axisZ, axisZ.mag());

        if (!result)
            break;
        
        i++;
    }

    return result;
}

const bool EngineMath::Intersect(const TerrainCell& Cell, const CV_AABB& AABB)
{
    return EngineMath::IntervalOverlap(Cell.Min, Cell.Max, AABB.GetMin(), AABB.GetMax());
}

const TerrainCell& EngineMath::GetTerrainCellByPosition(const TerrainModel& Terrain, const float cellwidth, const float x, const float z)
{
    int side = Terrain.GetSideLen();
    side -= 1;

    int i = int(x / cellwidth);
    i += side / 2;

    if (i >= side - 1)
        i = side - 1;

    else if (i < 0)
        i = 0;

    int j = int(z / cellwidth);
    j += side / 2;

    if (j >= side - 1)
        j = side - 1;

    else if (j < 0)
        j = 0;

    return Terrain.GetCellList()[j * side + i];
}

void EngineMath::SetMinMax(Vect& min, Vect& max)
{
    float tmp = min.X();
    if (tmp > max.X()) {
        min.X() = max.X();
        max.X() = tmp;
    }

    tmp = min.Y();
    if (tmp > max.Y()) {
        min.Y() = max.Y();
        max.Y() = tmp;
    }

    tmp = min.Z();
    if (tmp > max.Z()) {
        min.Z() = max.Z();
        max.Z() = tmp;
    }
}

void EngineMath::CheckMinMax(const Vect& vert, Vect& min, Vect& max)
{
    // Check if vertex has any points lower than min
    float tmp = vert.X();
    if (tmp < min.X())
        min.X() = tmp;

    tmp = vert.Y();
    if (tmp < min.Y())
        min.Y() = tmp;

    tmp = vert.Z();
    if (tmp < min.Z())
        min.Z() = tmp;

    // Check if vertex has any points higher than max
    tmp = vert.X();
    if (tmp > max.X())
        max.X() = tmp;

    tmp = vert.Y();
    if (tmp > max.Y())
        max.Y() = tmp;

    tmp = vert.Z();
    if (tmp > max.Z())
        max.Z() = tmp;
}
//
//void EngineMath::InterpolateOnTerrainCell(float& height, float& normal, const TerrainCell& Cell, const Vect& P, const float Beta, const float Gamma)
//{
//
//}

void EngineMath::CalculateBarycentricCord(float& height, Vect& normal, const TerrainCell& Cell, const Vect& P, const float CellWidth)
{
    // A=Cell.min, B=???, C=Cell.max
    // 
    // v0 = B-A, v1 = C-B, v2 = P-A
    // 
    // a = v0*v0, b = v1*v0, c = v1*v1, d = v2*v0, e = v2*v1
    //    We can solve for beta and gamma as follows:
    //      beta    = (dc-be)/(ac-b^2)
    //      gamma   = (ae-db)/(ac-b^2)

    UNREFERENCED_PARAMETER(CellWidth);

    const StandardVertex& A = *Cell.v0;
    const StandardVertex& C = *Cell.v3;
    StandardVertex B;

    const Vect v2 = P - Vect(A.x, A.y, A.z);

    if (v2.X() > v2.Z()) {
        B = *Cell.v1;
    }
    else {
        B = *Cell.v2;
    }

    const Vect v0 = Vect(B.x - A.x, B.y - A.y, B.z - A.z);
    const Vect v1 = Vect(C.x - B.x, C.y - B.y, C.z - B.z);

    float   a = v0.dot(v0),
        b = v1.dot(v0),
        c = v1.dot(v1),
        d = v2.dot(v0),
        e = v2.dot(v1);

    Visualizer::ShowMarkerPoint(Vect(A.x, A.y, A.z), Colors::Black);
    Visualizer::ShowMarkerPoint(Vect(B.x, B.y, B.z), Colors::Black);
    Visualizer::ShowMarkerPoint(Vect(C.x, C.y, C.z), Colors::Black);

    float beta = (d * c - b * e) / (a * c - b * b);
    float gamma = (a * e - d * b) / (a * c - b * b);

    height = A.y + beta * (B.y - A.y) + gamma * (C.y - B.y);

    Vect NA = Vect(A.nx, A.ny, A.nz);
    Vect NB = Vect(B.nx, B.ny, B.nz);
    Vect NC = Vect(C.nx, C.ny, C.nz);

    normal = NA + beta * (NB - NA) + gamma * (NC - NB);

    Vect point = 0.5f * (Cell.Max + Cell.Min);
    point.Y() = height;

    Vect point1 = P;
    point1.Y() = height;

    Visualizer::ShowMarkerPoint(P, Colors::Orange);
    Visualizer::ShowMarkerPoint(point1);
    Visualizer::ShowMarkerLine(point1, P, Colors::Blue);
    Visualizer::ShowMarkerLine(point1 + normal,  point1 + (2.0f * normal), Colors::Red);
}
//
//const bool EngineMath::LightInRenderDistance(const MOABEPointLight& pLight, const Vect& Point, const Vect& Direction, const float RenderDistance)
//{
//    const Vect V = (pLight.GetPosition() - Point);
//    if ()
//        return false;
//}
//
//float EngineMath::LightDistanceToPoint(const MOABEPointLight& pLight, const Vect& Point)
//{
//    return (pLight.GetPosition() - Point).mag();
//}
//
//float EngineMath::LightDistanceToPointSqr(const MOABEPointLight& pLight, const Vect& Point)
//{
//    return (pLight.GetPosition() - Point).magSqr();
//}
//
//float EngineMath::LightDistanceToPoint(const MOABESpotLight& pLight, const Vect& Point)
//{
//    return (pLight.GetPosition() - Point).mag();
//}
//
//float EngineMath::LightDistanceToPointSqr(const MOABESpotLight& pLight, const Vect& Point)
//{
//    return (pLight.GetPosition() - Point).magSqr();
//}
//
//const bool EngineMath::PointInCone(const Vect& TestPoint, const Vect& ConePoint, const Vect& Direction, const float ConeRange, const float ConeAngle)
//{
//    // test distance first
//    const Vect D = TestPoint - ConePoint;
//    const float DDistSqr = D.dot(D);
//    
//    if (DDistSqr >= ConeRange * ConeRange)
//        return false;
//
//    // then see if its cone
//    return std::powf(Direction.dot(D), 2.0f) < Direction.dot(Direction) * DDistSqr * std::powf(ConeAngle, 2.0f);
//}
//
//const bool EngineMath::PointInConePrecomputedDist(const Vect& TestPoint, const Vect& ConePoint, const Vect& Direction, const float ConeAngle, const float Distance)
//{
//    // test distance first
//    const Vect D = TestPoint - ConePoint;
//
//    return std::powf(Direction.dot(D), 2.0f) < Direction.dot(Direction) * Distance * std::powf(ConeAngle, 2.0f);
//}
