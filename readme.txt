game will have:
	main menu
	local leaderboards
	pause menu
	game over menu
	game window proper
	Optional: keybinds menu

Gameplay:
	player sprite will only be able to
		crouch
		jump
		
	Once gameplay starts, "running" automatically starts
		you cannot stop
		hitting bombs is game over
		missing the platform and falling below screen is game over
		
	Platforms are procedurally generated
	with bombs procedurally generated on the platforms
	
	score will be calculated on distance travelled and bombs dodged
	
	score will be kept track of
		upon game over, player asked to type name and name will be saved in external file, alongside score
	
Backend:
	all windows handled by states
		main menu state
		pause menu state
		game over state
		leaderboard state
		optionsl: keybind state
	player will have 2 states
		on-ground state
		in-air state
		
	Implementation of movement will be:
		player technically stands still but can jump/crouch
		platforms and bombs procedurally generated beyond right side of screen
			all platforms and bombs will then move left until they hit left of screen
			after with they respawn again right of screen w/ randomized attributes.