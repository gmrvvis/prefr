/*
 * Copyright (c) 2014-2019 GMRV/URJC.
 *
 * Authors: Cristian Rodríguez <cristian.rodriguez@urjc.es>
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
#ifndef __PREFR__GL_PICKRENDERER__
#define __PREFR__GL_PICKRENDERER__

#include <prefr/api.h>

#include "GLRenderer.h"
#include "GLRenderConfig.h"

#include <vector>

namespace prefr
{
  class GLPickRenderer : public GLRenderer
  {
  public:
    PREFR_API
    virtual ~GLPickRenderer( void );
    PREFR_API
    virtual uint32_t pick( int posX, int posY );
    PREFR_API
    virtual std::vector< uint32_t > pickArea( int minPointX, int minPointY, 
      int maxPointX, int maxPointY );

    PREFR_API
    void setWindowSize( uint32_t w, uint32_t h );

    PREFR_API
    void glPickProgram( IGLRenderProgram* renderProgram );
  protected:
    IGLRenderProgram* _glPickProgram;
    uint32_t framebuffer = -1;
    uint32_t textureColorbuffer = -1;
    uint32_t rbo = -1;
    uint32_t width = 500;
    uint32_t height = 500;
    bool recreateFBO = true;

    const uint32_t BACKGROUND_VALUE = 16646655;

  protected:
    void recreateFBOFunc( void );
    void drawFunc( void );
  };


}




#endif /* __PREFR__GL_PICKRENDERER__ */
