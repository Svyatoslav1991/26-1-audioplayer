# 26-1-audioplayer

Use classes to implement a program to simulate the operation of an audio player.
The player contains several audio recordings available for playback.
For them, you must create a separate Track class.
The fields of this class should be: name, creation date (here you can use the std::tm type) and the duration of the record in seconds.
The player itself is also implemented using a class.
Inside it should contain a list of available records and the fields necessary for the logic of the player.

The user interacts with the program using commands:
The play command prompts the user for the name of the recording to play and starts playing it. Playback is simulated by printing all the information about the recording to the console. If a recording is already in progress, nothing happens.
pause command. Pauses the recording, about which it displays the corresponding message in the console. If the recording is already paused or not playing at all, nothing happens.
The next command moves to the next record to play. The entry is randomly selected, as if the player were in shuffle mode.
The stop command stops playback of the current record, if any. A message about this is displayed in the console. It is impossible to stop playback twice, so the command should work only in the first case.
The exit command is an exit from the program.
