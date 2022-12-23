using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Threading;
using System.Threading.Tasks;

Console.WriteLine("Executing script code");
Console.WriteLine($"hello world {string.Join(",", args)}");

Console.WriteLine("Executing Chimp code");
ChimpsAtSea.BlamCreationSuite.Chimp.Commands.HelloWorldCommand helloWorld = new();
await helloWorld.Execute(args);
