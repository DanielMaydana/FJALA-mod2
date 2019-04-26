using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PracticandoBackEnd.ModelData
{
    public class PracticandoContext : DbContext
    {
        public PracticandoContext() : base("ServicesContext")
        {

        }

        public DbSet<Person> People { get; set; }

        public DbSet<Pet> Pets { get; set; }

        protected override void OnModelCreating(DbModelBuilder modelBuilder)
        {
            modelBuilder.Entity<Pet>()
                .HasRequired<Person>(pet => pet.CustomPerson)
                .WithMany(p => p.Pets)
                .HasForeignKey<Guid>(pet => pet.IdPerson);
        }
    }
}
