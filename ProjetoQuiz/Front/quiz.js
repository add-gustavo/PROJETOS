const buttons = document.querySelectorAll('button');

buttons.forEach(button => {
  const originalColor = button.style.backgroundColor;
  const borderColor = button.style.borderColor;

  button.addEventListener('mouseover', () => {
    button.style.backgroundColor = borderColor;
  });

  button.addEventListener('mouseout', () => {
    
    if (!button.classList.contains('clicked')) {
      button.style.backgroundColor = originalColor;
    }
  });

  button.addEventListener('click', () => {
    this.classList.add('clicked');
  });
});
