describe('First Test', () => {
  it('Visits the Google test', () => {
    cy.visit('https://google.am');
    cy.get('input').get('[class="gLFyf gsfi"]').type('test{enter}');
  })
})