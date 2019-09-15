
/*
 * StoryMode implements a story about 'Same Clip?'.
 *
 */

#include "Mode.hpp"
#include "Sound.hpp"

struct StoryMode : Mode {
	StoryMode();
	virtual ~StoryMode();

	virtual bool handle_event(SDL_Event const &, glm::uvec2 const &window_size) override;
	virtual void update(float elapsed) override;
	virtual void draw(glm::uvec2 const &drawable_size) override;

	//called to create menu for current scene:
	void enter_scene();

	//------ story state -------
	enum {
		s0, s1, s2, s3, s4,s5,
	} location = s0;
	int same = 0;
	int correct = 0;
	int wrong = 0;

	glm::vec2 view_min = glm::vec2(0,0);
	glm::vec2 view_max = glm::vec2(620, 480);

	//------ background music -------
	std::shared_ptr< Sound::PlayingSample > background_music;
};
