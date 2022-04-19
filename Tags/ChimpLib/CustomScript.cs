using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Threading;
using System.Threading.Tasks;
using Microsoft.CodeAnalysis.CSharp.Scripting;
using Microsoft.CodeAnalysis.Scripting;

namespace ChimpsAtSea.BlamCreationSuite.Chimp
{
    public static class CustomScripts
    {
        public class Globals
        {
            public string[] args;
        }

        public static async Task EvalAsync(string source, params string[] arguments)
        {
            await CSharpScript.EvaluateAsync(
                source,
                ScriptOptions.Default.WithReferences(typeof(CustomScripts).Assembly),
                new Globals { args = arguments });
        }
    }
}
