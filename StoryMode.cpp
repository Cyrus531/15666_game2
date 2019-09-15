#include "StoryMode.hpp"
#include "Sprite.hpp"
#include "DrawSprites.hpp"
#include "Load.hpp"
#include "data_path.hpp"
#include "gl_errors.hpp"
#include "MenuMode.hpp"
#include "Sound.hpp"

Sprite const *sprite_s0 = nullptr;
Sprite const *sprite_s1 = nullptr;
Sprite const *sprite_s2 = nullptr;
Sprite const *sprite_s3 = nullptr;
Sprite const *sprite_s4 = nullptr;
Sprite const *sprite_s5 = nullptr;

Load< SpriteAtlas > sprites(LoadTagDefault, []() -> SpriteAtlas const * {
	SpriteAtlas const *ret = new SpriteAtlas(data_path("sameclip"));

	sprite_s0 = &ret->lookup("s0");
	sprite_s1 = &ret->lookup("s1");
	sprite_s2 = &ret->lookup("s2");
	sprite_s3 = &ret->lookup("s3");
	sprite_s4 = &ret->lookup("s4");
	sprite_s5 = &ret->lookup("s5");

	return ret;
});

Load< Sound::Sample > music_cold_dunes(LoadTagDefault, []() -> Sound::Sample * {
	return new Sound::Sample(data_path("cold-dunes.opus"));
});

Load< Sound::Sample > music_0(LoadTagDefault, []() -> Sound::Sample * {
	return new Sound::Sample(data_path("0.opus"));
});

Load< Sound::Sample > music_1(LoadTagDefault, []() -> Sound::Sample * {
	return new Sound::Sample(data_path("1.opus"));
});
Load< Sound::Sample > music_2(LoadTagDefault, []() -> Sound::Sample * {
	return new Sound::Sample(data_path("2.opus"));
});

Load< Sound::Sample > music_3(LoadTagDefault, []() -> Sound::Sample * {
	return new Sound::Sample(data_path("3.opus"));
});

Load< Sound::Sample > music_4(LoadTagDefault, []() -> Sound::Sample * {
	return new Sound::Sample(data_path("4.opus"));
});

Load< Sound::Sample > music_5(LoadTagDefault, []() -> Sound::Sample * {
	return new Sound::Sample(data_path("5.opus"));
});

Load< Sound::Sample > music_6(LoadTagDefault, []() -> Sound::Sample * {
	return new Sound::Sample(data_path("6.opus"));
});

Load< Sound::Sample > music_7(LoadTagDefault, []() -> Sound::Sample * {
	return new Sound::Sample(data_path("7.opus"));
});

Load< Sound::Sample > music_8(LoadTagDefault, []() -> Sound::Sample * {
	return new Sound::Sample(data_path("8.opus"));
});

Load< Sound::Sample > music_9(LoadTagDefault, []() -> Sound::Sample * {
	return new Sound::Sample(data_path("9.opus"));
});


StoryMode::StoryMode() {
}

StoryMode::~StoryMode() {
}

bool StoryMode::handle_event(SDL_Event const &, glm::uvec2 const &window_size) {
	if (Mode::current.get() != this) return false;

	return false;
}

void StoryMode::update(float elapsed) {
	if (Mode::current.get() == this) {
		//there is no menu displayed! Make one:
		enter_scene();
	}

}

void StoryMode::enter_scene() {
	//just entered this scene, adjust flags and build menu as appropriate:
	std::vector< MenuMode::Item > items;
	glm::vec2 at(170.0f, view_max.y - 120.0f);
	auto add_text = [&items,&at](std::string text) {
		while (text.size()) {
			auto end = text.find('\n');
			items.emplace_back(text.substr(0, end), nullptr, 1.5f, glm::u8vec4(0xff, 0xff, 0xff, 0xff), nullptr, at);
			at.y -= 13.0f;
			if (end == std::string::npos) break;
			text = text.substr(end+1);
		}
		at.y -= 20.0f;
	};
	auto add_choice = [&items,&at](std::string const &text, std::function< void(MenuMode::Item const &) > const &fn) {
		items.emplace_back(text, nullptr, 2.0f, glm::u8vec4(0xff, 0xff, 0xff, 0xff), fn, at + glm::vec2(16.0f, 0.0f));
		items.back().selected_tint = glm::u8vec4(0x88, 0x00, 0x88, 0xff);
		at.y -= 70.0f;
	};

	if (location == s0) {
		add_text("Same clip? (each clip played after 3 beeps)");
		same = rand() % 2;
		if (same == 1) {
			Sound::play(*music_0, 1.0f);
		} else {
			Sound::play(*music_1, 1.0f);
		}

		at.y -= 100.0f; //gap before choices
		add_choice("Yes", [this](MenuMode::Item const &){
			if (same == 1) {
				location = s1;
				correct += 1;
			} else {
				location = s0;
				wrong += 1;
			}
			Sound::stop_all_samples();
			Mode::current = shared_from_this();
		});
		add_choice("No", [this](MenuMode::Item const &){
			if (same != 1) {
				location = s1;
				correct += 1;
			} else {
				location = s0;
				wrong += 1;
			}
			Sound::stop_all_samples();
			Mode::current = shared_from_this();
		});
	} else if (location == s1) {
		add_text("Same clip? (each clip played after 3 beeps)");
		same = rand() % 2;
		if (same == 1) {
			Sound::play(*music_2, 1.0f, 3.0f);
		} else {
			Sound::play(*music_3, 1.0f, 3.0f);
		}

		at.y -= 100.0f; //gap before choices
		add_choice("Yes", [this](MenuMode::Item const &){
			if (same == 1) {
				location = s2;
				correct += 1;
			} else {
				location = s0;
				wrong += 1;
			}
			Sound::stop_all_samples();
			Mode::current = shared_from_this();
		});
		add_choice("No", [this](MenuMode::Item const &){
			if (same != 1) {
				location = s2;
				correct += 1;
			} else {
				location = s0;
				wrong += 1;
			}
			Sound::stop_all_samples();
			Mode::current = shared_from_this();
		});
	} else if (location == s2) {
		add_text("Same clip? (each clip played after 3 beeps)");
		same = rand() % 2;
		if (same == 1) {
			Sound::play(*music_4, 1.0f);
		} else {
			Sound::play(*music_5, 1.0f);
		}

		at.y -= 100.0f; //gap before choices
		add_choice("Yes", [this](MenuMode::Item const &){
			if (same == 1) {
				location = s3;
				correct += 1;
			} else {
				location = s1;
				wrong += 1;
			}
			Sound::stop_all_samples();
			Mode::current = shared_from_this();
		});
		add_choice("No", [this](MenuMode::Item const &){
			if (same != 1) {
				location = s3;
				correct += 1;
			} else {
				location = s1;
				wrong += 1;
			}
			Sound::stop_all_samples();
			Mode::current = shared_from_this();
		});
	} else if (location == s3) {
		add_text("Same clip? (each clip played after 3 beeps)");
		same = rand() % 2;
		if (same == 1) {
			Sound::play(*music_6, 1.0f);
		} else {
			Sound::play(*music_7, 1.0f);
		}

		at.y -= 100.0f; //gap before choices
		add_choice("Yes", [this](MenuMode::Item const &){
			if (same == 1) {
				location = s4;
				correct += 1;
			} else {
				location = s2;
				wrong += 1;
			}
			Sound::stop_all_samples();
			Mode::current = shared_from_this();
		});
		add_choice("No", [this](MenuMode::Item const &){
			if (same != 1) {
				location = s4;
				correct += 1;
			} else {
				location = s2;
				wrong += 1;
			}
			Sound::stop_all_samples();
			Mode::current = shared_from_this();
		});
	} else if (location == s4) {
		add_text("Same clip? (each clip played after 3 beeps)");
		same = rand() % 2;
		if (same == 1) {
			Sound::play(*music_8, 1.0f);
		} else {
			Sound::play(*music_9, 1.0f);
		}

		at.y -= 100.0f; //gap before choices
		add_choice("Yes", [this](MenuMode::Item const &){
			if (same == 1) {
				location = s5;
				correct += 1;
			} else {
				location = s3;
				wrong += 1;
			}
			Sound::stop_all_samples();
			Mode::current = shared_from_this();
		});
		add_choice("NO", [this](MenuMode::Item const &){
			if (same != 1) {
				location = s5;
				correct += 1;
			} else {
				location = s3;
				wrong += 1;
			}
			Sound::stop_all_samples();
			Mode::current = shared_from_this();
		});
	} else {
		add_text("Congrats, you won!");
		add_text("num correct : " + std::to_string(correct));
		add_text("num wrong   : " + std::to_string(wrong));

		Sound::play(*music_cold_dunes, 1.0f);

		at.y -= 100.0f; //gap before choices
		add_choice("END", [this](MenuMode::Item const &){
			location = s5;
			Mode::current = nullptr;
		});
	}
	std::shared_ptr< MenuMode > menu = std::make_shared< MenuMode >(items);
	menu->atlas = sprites;
	menu->view_min = view_min;
	menu->view_max = view_max;
	menu->background = shared_from_this();
	Mode::current = menu;
}

void StoryMode::draw(glm::uvec2 const &drawable_size) {
	//clear the color buffer:
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	//use alpha blending:
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//don't use the depth test:
	glDisable(GL_DEPTH_TEST);

	{ //use a DrawSprites to do the drawing:
		DrawSprites draw(*sprites, view_min, view_max, drawable_size, DrawSprites::AlignPixelPerfect);
		glm::vec2 ul = glm::vec2(view_min.x, view_max.y);
		if (location == s0) {
			draw.draw(*sprite_s0, ul);
		} else if (location == s1) {
			draw.draw(*sprite_s1, ul);
		} else if (location == s2) {
			draw.draw(*sprite_s2, ul);
		} else if (location == s3) {
			draw.draw(*sprite_s3, ul);
		} else if (location == s4) {
			draw.draw(*sprite_s4, ul);
		} else if (location == s5) {
			draw.draw(*sprite_s5, ul);
		} 
	}
	GL_ERRORS(); //did the DrawSprites do something wrong?
}
