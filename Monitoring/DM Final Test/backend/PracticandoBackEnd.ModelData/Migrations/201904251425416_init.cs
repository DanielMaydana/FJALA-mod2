namespace PracticandoBackEnd.ModelData.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class init : DbMigration
    {
        public override void Up()
        {
            CreateTable(
                "dbo.People",
                c => new
                    {
                        IdPerson = c.Guid(nullable: false),
                        Name = c.String(),
                    })
                .PrimaryKey(t => t.IdPerson);
            
            CreateTable(
                "dbo.Pets",
                c => new
                    {
                        IdPet = c.Guid(nullable: false),
                        Name = c.String(),
                        IdPerson = c.Guid(nullable: false),
                    })
                .PrimaryKey(t => t.IdPet)
                .ForeignKey("dbo.People", t => t.IdPerson, cascadeDelete: true)
                .Index(t => t.IdPerson);
            
        }
        
        public override void Down()
        {
            DropForeignKey("dbo.Pets", "IdPerson", "dbo.People");
            DropIndex("dbo.Pets", new[] { "IdPerson" });
            DropTable("dbo.Pets");
            DropTable("dbo.People");
        }
    }
}
