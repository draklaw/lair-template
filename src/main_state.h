/*
 *  Copyright (C) 2016 the authors (see AUTHORS)
 *
 *  This file is part of ld36.
 *
 *  lair is free software: you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  lair is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with lair.  If not, see <http://www.gnu.org/licenses/>.
 *
 */


#ifndef LD36_MAIN_STATE_H
#define LD36_MAIN_STATE_H


#include <lair/core/signal.h>
#include <lair/core/json.h>

#include <lair/utils/game_state.h>
#include <lair/utils/interp_loop.h>
#include <lair/utils/input.h>

#include <lair/render_gl2/orthographic_camera.h>
#include <lair/render_gl2/render_pass.h>

#include <lair/ec/entity.h>
#include <lair/ec/entity_manager.h>
#include <lair/ec/sprite_component.h>
#include <lair/ec/bitmap_text_component.h>


using namespace lair;


class Game;


class MainState : public GameState {
public:
	MainState(Game* game);
	virtual ~MainState();

	virtual void initialize();
	virtual void shutdown();

	virtual void run();
	virtual void quit();

	Game* game();

	void startGame();
	void updateTick();
	void updateFrame();

	void resizeEvent();

	EntityRef loadEntity(const Path& path, EntityRef parent,
	                     const Path& cd = Path());

	RenderPass* renderPass() { return &_mainPass; }
	SpriteRenderer* spriteRenderer() { return &_spriteRenderer; }

protected:
	// More or less system stuff

	RenderPass                 _mainPass;

	EntityManager              _entities;

	SpriteRenderer             _spriteRenderer;
	SpriteComponentManager     _sprites;
	BitmapTextComponentManager _texts;
//	AnimationComponentManager  _anims;
	InputManager               _inputs;

	SlotTracker _slotTracker;

	OrthographicCamera _camera;

	bool       _initialized;
	bool       _running;
	InterpLoop _loop;
	int64      _fpsTime;
	unsigned   _fpsCount;
	uint64     _prevFrameTime;

	Input* _quitInput;
	Input* _restartInput;
	Input* _skipInput;
};


#endif
