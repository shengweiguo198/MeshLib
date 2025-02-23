#pragma once
#include "MRMeshFwd.h"
#include "MRObjectMeshHolder.h"

namespace MR
{

/// Object to show plane feature
/// \ingroup FeaturesGroup
class MRMESH_CLASS PlaneObject : public ObjectMeshHolder
{
public:
    /// Creates simple plane object 
    MRMESH_API PlaneObject();
    /// Finds best plane to approx given points
    MRMESH_API PlaneObject( const std::vector<Vector3f>& pointsToApprox );

    PlaneObject( PlaneObject&& ) noexcept = default;
    PlaneObject& operator = ( PlaneObject&& ) noexcept = default;
    virtual ~PlaneObject() = default;

    constexpr static const char* TypeName() noexcept { return "PlaneObject"; }
    virtual const char* typeName() const override { return TypeName(); }

    /// \note this ctor is public only for std::make_shared used inside clone()
    PlaneObject( ProtectedStruct, const PlaneObject& obj ) : PlaneObject( obj )
    {}

    virtual std::string getClassName() const override { return "Plane"; }

    MRMESH_API virtual std::shared_ptr<Object> clone() const override;
    MRMESH_API virtual std::shared_ptr<Object> shallowClone() const override;

    /// calculates normal from xf
    MRMESH_API Vector3f getNormal() const;
    /// calculates center from xf
    MRMESH_API Vector3f getCenter() const;
    /// updates xf to fit given normal
    MRMESH_API void setNormal( const Vector3f& normal );
    /// updates xf to fit given center
    MRMESH_API void setCenter( const Vector3f& center );
    /// updates xf to scale size
    MRMESH_API void setSize( float size );
protected:
    PlaneObject( const PlaneObject& other ) = default;

    /// swaps this object with other
    MRMESH_API virtual void swapBase_( Object& other ) override;

    MRMESH_API virtual void serializeFields_( Json::Value& root ) const override;

    virtual tl::expected<std::future<void>, std::string> serializeModel_( const std::filesystem::path& ) const override
    { return {}; }

    virtual tl::expected<void, std::string> deserializeModel_( const std::filesystem::path&, ProgressCallback ) override
    { return {}; }

private:
    void constructMesh_();
};

}
