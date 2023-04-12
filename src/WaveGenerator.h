#pragma once
#include <functional>
#include "SFML/Graphics.hpp"

/// <summary>
/// The drawing mode for each point in the wave
/// </summary>
enum class DrawingMode
{
	CURVE,					//!< Wave as a curve
	CIRCLE,					//!< Wave as a circles
	CIRCLE_TRANSPARENT		//!< Wave as a transparent circles
};

class WaveGenerator
{
public:
	/// <summary>
	/// Construct a new Wave Generator object
	/// </summary>
	/// <param name="windowWidth">Width of the window</param>
	/// <param name="windowHeight">Height of the window</param>
	/// <param name="windowTitle">Title of the window</param>
	/// <param name="framerate">Framerate of the simulation</param>
	WaveGenerator(unsigned windowWidth, unsigned windowHeight, std::string windowTitle, unsigned framerate);
	/// <summary>
	/// Run Simulation
	/// </summary>
	void run();
private:
	/// <summary>
	/// Handle user event
	/// </summary>
	void pollEvent();
	/// <summary>
	/// Update the simulation
	/// </summary>
	void update();
	/// <summary>
	/// Draw on window
	/// </summary>
	void draw();
private:
	sf::RenderWindow m_window;										//!< Window to draw on
	std::vector<std::function<float(float)>> m_functionVec;			//!< Functions vector to simulate
	int m_fps;														//!< Simulation Framerate;
	int m_functionID{ 0 };											//!< Id of current function
	DrawingMode m_drawMode{ DrawingMode::CURVE };					//!< Drawing mode of each point
	// Function settings
	float m_aplitude;												//!< Wave amplitude
	float m_interval;												//!< The distance between x points (precision)
	float m_phaseShift;												//!< Horizontal shift
	float m_verticalShift;											//!< Vertical shift
	float m_period;													//!< Distance between peaks
};