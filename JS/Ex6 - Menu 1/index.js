let cardsHTML = document.querySelectorAll('.square');
let i = 0;

for (card of cardsHTML) {
  card.style.animationDelay = `${i}s`;
  i++;
}