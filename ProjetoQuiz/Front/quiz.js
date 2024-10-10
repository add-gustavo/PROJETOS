const buttons = document.querySelectorAll('button');

buttons.forEach(button => {
  button.addEventListener('click', () => {
    button.style.backgroundColor = button.style.borderColor;
  });
});
