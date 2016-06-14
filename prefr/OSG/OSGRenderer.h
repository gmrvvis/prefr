/*
 * Copyright (c) 2014-2016 GMRV/URJC.
 *
 * Authors: Sergio Galindo <sergio.galindo@urjc.es>
 *
 * This file is part of PReFr <https://gmrv.gitlab.com/nsviz/prefr>
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License version 3.0 as published
 * by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */
#ifndef __PREFR__OSG_RENDERER__
#define __PREFR__OSG_RENDERER__

#include <prefr/api.h>
#include "../Renderer.h"
#include "OSGRenderConfig.h"
#ifndef PREFR_SKIP_GLEW_INCLUDE
#include <GL/glew.h>
#endif

#ifdef PREFR_USE_OPENSCENEGRAPH

#include <osg/Array>
#include <osg/Geometry>

#include <osg/NodeVisitor>

#include <osgGA/StandardManipulator>
#include <osgGA/TrackballManipulator>

#include <osgDB/FileUtils>

#include <osgViewer/View>
#include <osgViewer/Viewer>
#include <osgViewer/CompositeViewer>
#include <osg/State>
#include <osg/GL>
#include <osg/BlendFunc>

namespace prefr
{

  class OSGRenderer : public Renderer, public osg::Drawable
  {
  public:

    PREFR_API
    OSGRenderer( );

    PREFR_API
    virtual ~OSGRenderer();

    PREFR_API
    void init( );

    PREFR_API
    virtual void SetupRender( void );

    PREFR_API
    virtual void Paint( void ) const;


    // OSG specific methods

    PREFR_API
    OSGRenderer( const OSGRenderer& other, const osg::CopyOp& copyop );

    META_Object( prefr::OSGRenderer, OSGRenderer )

    PREFR_API
    void compileGLObjects( osg::RenderInfo& renderInfo ) const;
    PREFR_API
    virtual void releaseGLObjects(osg::State* state) const;

    PREFR_API
//    virtual osg::BoundingBox computeBound( ) const;
    virtual osg::BoundingSphere computeBound( ) const;

    PREFR_API
    virtual void accept(osg::PrimitiveFunctor& functor) const;

    PREFR_API
    virtual void drawImplementation( osg::RenderInfo& renderInfo ) const;


  protected:



  };


}

#endif


#endif /* __PREFR__OSG_RENDERER__ */
