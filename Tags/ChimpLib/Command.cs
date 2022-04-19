using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Threading;
using System.Threading.Tasks;

namespace ChimpsAtSea.BlamCreationSuite.Chimp
{
    public interface ICommand
    {
        public string Name { get; }

        public Task Execute(params string[] args);
    }

    public class CommandExecutor
    {
        private List<ICommand> _commands = new List<ICommand>
        {
            new Commands.EvalCommand(),
            new Commands.ScriptCommand(),
            new Commands.HelloWorldCommand(),
        };

        public CommandExecutor()
        {
            // this is where you could load libraries for commands
        }

        public async Task Execute(string commandName, params string[] args)
        {
            var command = _commands.Find(x => x.Name == commandName);

            if (command == null)
            {
                throw new ArgumentException($"{commandName} does not exist in the list of commands.");
            }

            await command.Execute(args);
        }
    }
}
