Dependency mod. Causes multiplayer clients to correctly load the AWESOME Sink point values for base-game items.




# Fix Client Resource Sink Points

This mod causes multiplayer clients to load the AWESOME Sink point values for base-game items,
which are normally skipped during the client's loading process.
This allows other mods to perform operations with these values without having to ask the server for this data.

This mod is intended as a dependency for other mods to require if they want access to this information,
there is no reason to install this mod on its own as an end user.

For example, [TFIT](https://ficsit.app/mod/TFIT) depends on this mod for the Sink Points Tooltip to function on multiplayer clients.

The only thing this mod does is load the sink point values for clients,
it does not change the values in any way.
Modded items are unaffected as their sink point values are already loaded.

This mod only needs to exist on the client side to function,
however, server versions of the mod are published
so that mods which must be installed on both sides can safely depend on this mod.
The mod has no effect if loaded server side.

## Credits

- Th3Fanbus for writing basically all of the mod
- Th3Fanbus and Mircea for doing the code digging required to figure this out
