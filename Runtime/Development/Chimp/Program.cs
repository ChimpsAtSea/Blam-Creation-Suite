using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace ChimpsAtSea.BlamCreationSuite.Chimp.Launcher
{
    public class Program
    {
        public static CommandExecutor CommandExecutor = new();

        private static async Task Main(string[] args)
        {
#if !DEBUG
            try
            {
#endif
                // Filter BCS command line options. Not bulletproof
                var filter = new List<string>(args);
                filter.RemoveAll(x => x.StartsWith('-'));

                await CommandExecutor.Execute(args[0], filter.Skip(1).ToArray());
#if !DEBUG
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Caught a fatal exception:\n{ex.Message}\nStack trace:{ex.StackTrace}");
            }
#endif
        }
    }
}
