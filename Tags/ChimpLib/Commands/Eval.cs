using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Threading;
using System.Threading.Tasks;

namespace ChimpsAtSea.BlamCreationSuite.Chimp.Commands
{
    public class EvalCommand : ICommand
    {
        public string Name { get => "eval"; }

        public async Task Execute(string[] args) => await CustomScripts.EvalAsync(args[0]);
    }

    public class ScriptCommand : ICommand
    {
        public string Name { get => "script"; }

        public async Task Execute(string[] args) => await CustomScripts.EvalAsync(File.ReadAllText(args[0]), args.Skip(1).ToArray());
    }
}
