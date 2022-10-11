using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Threading;
using System.Threading.Tasks;

#pragma warning disable CS1998 // Async method lacks 'await' operators and will run synchronously

namespace ChimpsAtSea.BlamCreationSuite.Chimp.Commands
{
    public class HelloWorldCommand : ICommand
    {
        public string Name { get => "hello-world"; }

        public async Task Execute(string[] args)
        {
            Console.WriteLine($"hello world {string.Join(",", args)}");
        }
    }
}
